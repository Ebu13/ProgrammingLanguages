(defun calculate-postfix (expression)
  (let ((stack '()))
    (dolist (token expression)
      (cond
        ((numberp token) (push token stack))
        ((member token '(+ - * /))
          (let ((op2 (pop stack))
                (op1 (pop stack)))
            (case token
              (+ (push (+ op1 op2) stack))
              (- (push (- op1 op2) stack))
              (* (push (* op1 op2) stack))
              (/ (push (/ op1 op2) stack)))))))
    (pop stack)))

(defun read-postfix-expression ()
  (format t "Postfix ifadeyi gir: ")
  (finish-output)
  (read))

(defun run-calculator ()
  (let ((expression (read-postfix-expression)))
    (format t "Sonuc: ~a~%" (calculate-postfix expression))))

(run-calculator)