setwd("/Users/soeren/Downloads")

A <- as.matrix(read.table("A-small-attempt1.in.txt", sep="\n"))
(itr <- as.numeric(A[1,]))


swap <- function(S, k){
  S[,k] <- 1-S[,k]
  return(S)
}
me <- function(S,D){
  sum(sort(apply(S,1,function(x)paste0(x,collapse ='')))!=sort(apply(D,1,function(x)paste0(x,collapse =''))))==0
}
r <- function(S,D,i,s, b){ 
  if(i > L){ 
    if(me(S,D) && s < b){
      return(s)
    }else{return(b)}
  }else{
    if( sum(S[,i]) == sum(D[,i]) ){
      b <- return(r(S, D, i+1, s, b))
    }
    if(sum(S[,i]) == N - sum(D[,i])){
      b <- return(r(swap(S,i), D, i+1, s+1, b))
    }
  }
  return(b)
}


for(i in 1:itr){
  Para <- as.numeric(unlist(strsplit(A[3*i-1,], "[^[:digit:]]")))
  N <- Para[1]
  L <- Para[2]
  Steck <- unlist(strsplit(A[3*i,], ""))
  Dev <- unlist(strsplit(A[3*i+1,], ""))
  S <- t(matrix(as.numeric(Steck[Steck!=' ']), L, N))
  D <- t(matrix(as.numeric(Dev[Dev!=' ']),L , N))

  s <- r(S,D,1,0,1000)
  
  if( s != 1000){
    write(paste0("Case #",i, ": ", s), file="A", append=TRUE)
  }else{
    write(paste0("Case #",i, ": ", "NOT POSSIBLE"), file="A", append=TRUE) 
  }
}


