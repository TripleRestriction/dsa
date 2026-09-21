(define my-list '(4 9 3 10 5 6))
(display my-list)
(newline)

(define (bubble-pass lst)
  (cond ((null? lst) '())
        ((null? (cdr lst)) lst)
        (else
         (let ((first (car lst))
               (second (cadr lst))
               (rest (cddr lst)))
           (if (> first second)
               (cons second (bubble-pass (cons first rest)))
               (cons first (bubble-pass (cdr lst))))))))

(define (bubble-sort lst)
  (let ((passed (bubble-pass lst)))
    (if (equal? passed lst)
        lst
        (bubble-sort passed))))

(display (bubble-sort my-list))
(newline)
