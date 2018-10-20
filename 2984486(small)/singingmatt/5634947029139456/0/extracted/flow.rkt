#lang racket
(require test-engine/racket-tests)
(require 2htdp/batch-io)

(define (explode str)
  (if (string=? str "") empty
      (cons (substring str 0 1) (explode (substring str 1)))))
(check-expect (explode "01") (list "0" "1"))

;; A Device is a fixed [List {0, 1}]
;; A Outlet is a [List {0, 1}] that can be adjusted
;; A Binary is a Device or Outlet

;; flip : Outlet x Natural -> Outlet
;; Flip an outlet at the nth place
(define (flip o n)
  (match n
    [0
     (match o
       [(cons 0 x) (cons 1 x)]
       [(cons 1 x) (cons 0 x)])]
    [_ (cons (first o) (flip (rest o) (sub1 n)))]))
(check-expect (flip '(0 1 0) 1) '(0 0 0))

;; flip-outlets : [List Outlet] x Natural -> [List Outlet]
;; flip all the outlets at n
(define (flip-outlets loo n)
  (map (λ (o) (flip o n)) loo))
(check-expect (flip-outlets '((0 1) (1 1)) 1) '((0 0) (1 0)))

;; list=? : [List X] x [List Y] -> Boolean
;; Are the lists equal?
(define (list=? x y)
  (and (= (length x) (length y))
       (local ((define (helper x y)
                 (or (and (empty? x) (empty? y))
                     (and (member (first x) y)
                          (helper (rest x) (remove (first x) y))))))
         (helper x y))))
(check-expect (list=? '((0 1) (1 0)) '((1 0) (0 1))) true)

;; places-differ : Binary x Binary -> [List Boolean]
;; sum the list
(define (places-differ b1 b2)
  (map = b1 b2))
(check-expect (places-differ '(0 1) '(1 0)) (list false false))

;; differences : Device x [List Outlet] -> [List Boolean]
;; The difference between the sums of the numbers
(define (differences d loo)
  (map (λ (o) (places-differ d o)) loo))
(check-expect (differences '(0 1) '((0 1) (1 0) (0 0) (1 1)))
              '((#t #t) (#f #f) (#t #f) (#f #t)))

;; false-count : [List Boolean] -> Natural
;; How many times false appears
(define (f-count lob)
  (foldl (λ (b n) (if b  n (add1 n))) 0 lob))
(check-expect (f-count (list true false true false)) 2)

;; member-all : [List Boolean] x [Listof [List Boolean]] -> Boolean
;; Is b present in every lob?
(define (member-all b lolob)
  (andmap (λ (lob) (member b lob)) lolob))

;; list-difs : [List Device] x [List Outlet] -> [List [List Dif]]
;; The differences between the devices and outlets
(define (list-difs lod loo)
  (map (λ (d) (differences d loo)) lod))
(check-expect (list-difs '((0 1) (1 1) (1 0)) '((1 1) (0 0) (1 0)))
              (list (list (list false true) (list true false) (list false false))
                    (list (list true true) (list false false) (list true false))
                    (list (list true false) (list false true) (list true true))))
;; difs-in-all : [List [List Dif]] -> [List [List Dif]]
;; difs present in all lod
(define (difs-in-all list-difs)
  (filter (λ (dif) (member-all dif (rest list-difs)))
          (first list-difs)))
(check-expect (difs-in-all (list-difs '((0 1) (1 1) (1 0)) '((1 1) (0 0) (1 0))))
              (list (list true false)))

;; min-dif : (cons Dif [List Dif]) -> Natural
;; Smallest difference
(define (min-dif lod)
  (foldl (λ (lod num) (local ((define false-count (f-count lod)))
                        (if (> num false-count) false-count num)))
         (f-count (first lod))
         (rest lod)))
(check-expect (min-dif (list (list true false) (list false false))) 1)



;; main : [List Device] x [List Outlet] -> Outpuet
(define (main lod loo)
  (local ((define l-d (list-difs lod loo))
          (define possible-difs (difs-in-all l-d)))
    (if (empty? possible-difs) "NOT POSSIBLE"
        (min-dif possible-difs))))
(check-expect (main '((0 1) (1 1) (1 0)) '((1 1) (0 0) (1 0))) 1)
(check-expect (main '((0 1) (1 0)) '((1 0) (0 1))) 0)
(check-expect (main '((1 0 1) (1 1 1)) '((0 1 0) (0 0 1))) "NOT POSSIBLE")
(define (2lines->output line1 line2)
  (local ((define m (main (map (λ (line1s) (map string->number (explode line1s))) line1)
                          (map (λ (line1s) (map string->number (explode line1s))) line2))))
    (if (number? m) (number->string m) m)))
(check-expect (2lines->output (list "01" "11" "10")
                              (list "11" "00" "10")) "1")
(define (file->output los-first-removed)
  (local ((define (loop contents i)
            (if (empty? contents) ""
                (string-append "Case #" (number->string i) ": "
                                (2lines->output (second contents) (third contents)) "\n"
                                (loop (rest (rest (rest contents))) (add1 i))))))
    (loop los-first-removed 1)))
(test)
(write-file "aout.txt" (file->output (rest (read-words/line "A-small-attempt0.in"))))