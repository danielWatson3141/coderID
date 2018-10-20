runs <- 5*10^4
n <- 1000
big_table <- matrix(0, nrow = n, ncol = n)


for (i in 1:10) {
  print(i)
  start <- proc.time()
  results <- matrix(nrow = runs, ncol = n)

  for (run in 1:runs) {
    a <- 1:n
    p <- sample(1:n, n, replace = TRUE)
    for (k in 1:n) {
      temp <- a[p[k]]
      a[p[k]] <- a[k]
      a[k] <- temp
    }
  results[run,] <- a
  }
  for (j in 1:n) {
    big_table[j,] <- big_table[j,] + (table(c(results[,j],1:n))-1)
  }
  print(proc.time() - start)
}



data <- read.table("C-small-attempt0.in", fill = TRUE)
data <- data[2*(1:120),] + 1
#data <- data[2*(1:2),] + 1

output <- data.frame(matrix(nrow = 120, ncol = 1))

for (i in 1:nrow(data)) {
  prob <- 0
  for (j in 1:ncol(data)) {
    prob <- prob + log(big_table[j,data[i,j]])
  }
  if (prob > n*log(500)) {
    output[i,1] <- paste("Case #",i,": BAD",sep="")
  } else {
    output[i,1] <- paste("Case #",i,": GOOD",sep="")
  }
}

write.table(output, "ProblemC.txt", quote = FALSE, row.names = FALSE, col.names = FALSE)