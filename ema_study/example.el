(buffer-name)
(buffer-file-name)"/home/yang/c_study/ema_study/example.el"
(current-buffer)
(other-buffer)#<buffer *scratch*>
(switch-to-buffer (other-buffer))
(point)
(buffer-size)
(defun multiply-by-seven (number)
  "Multiply NUMBER by seven."
  (* 7 number))
(multiply-by-seven 8)
  int main()
  {
    int i;
    for (i = 0; i < 10; i++)
      {
	printf("%d ",i);
      }
    return 0;
  }
(defun multiply-by-seven (number)       ; Interactive version.
  "Multiply NUMBER by seven."
  (interactive "p")
  (message "The result is %d" (* 7 number)))
(let ((zebra "stripes")
      (tiger "fierce"))
  (message "One kind of animal has %s and another is %s."
           zebra tiger))
(defun type-of-animal (characteristic)
  "Print message in echo area depending on CHARACTERISTIC.
If the CHARACTERISTIC is the string \"fierce\",
then warn of a tiger."
  (if (equal characteristic "fierce")
      (message "It is a tiger!")))
(type-of-animal "fierce")
(type-of-animal "tiger")
(defun type-of-animal (characteristic)  ; Second version.
  "Print message in echo area depending on CHARACTERISTIC.
If the CHARACTERISTIC is the string \"fierce\",
then warn of a tiger; else say it is not fierce."
  (if (equal characteristic "fierce")
      (message "It is a tiger!")
    (message "It is not fierce!")))
(type-of-animal "fierce")
(type-of-animal "striped")
(defun simplified-end-of-buffer()
  "thisblank is used to goto the end of buffer"
  (interactive)
  (push-mark)
  (goto-char (point-max)))
  (simplified-end-of-buffer)
 
(defun if-get-buffer(buffer)
  "print a message about the exist of buffer"
  (interactive "*bbuffer: ")
  (if (get-buffer buffer)
      (message "buffer exist")
    (message "buffer don't exist")))
(if-get-buffer (current-buffer))
(message "Line %d"
	 (1+ (count-lines 1 (point))))
(car '(rose violet daisy buttercup))
(cdr '(rose violet daisy buttercup))
(cons 'pine '(fir oak maple))
(setq animals (list 'antelope 'giraffe 'lion 'tiger))
(setcar animals 'hippopotamus)
(message "%s"
	 animals)
(setcdr animals '(cat dog))(cat dog)
(message "%s" animals)"(hippopotamus cat dog)"
(cons "another piece"
      '("a piece of text" "previous piece"))("another piece" "a piece of text" "previous piece")
 
      (describe-variable 'animals)
      ）

(describe-variable 'kill-ring)
(setq bouquet '(rose violet buttercup))
(setq flowers (cdr bouquet))
(setq bouquet (cons 'lily bouquet))
(eq (cdr (cdr bouquet)) flowers)t
(setq empty-list ())
animals
(setq animals '(gazelle giraffe tiger))

(defun print-elements-of-list (list)
  "Print each element of LIST on a line of its own."
  (while list
    (print (car list))
    (setq list (cdr list))))

(print-elements-of-list animals)nil
(defun sum_from_1_to_7()
  (while (> num 0)
    (progn
      (setq total (+ total num))
      (setq num (- num 1)))))
(setq num 7)
(setq total 0)
(sum_from_1_to_7)
(eq total 28)
(message "%d" total)"28"


(defun triangle (number-of-rows)    ; Version with
                                    ;   incrementing cojunter.
  "Add up the number of pebbles in a triangle.
The first row has one pebble, the second row two pebbles,
the third row three pebbles, and so on.
The argument is NUMBER-OF-ROWS."

  (let ((total 0)
        (row-number 1))
    (while (<= row-number number-of-rows)
      (setq total (+ total row-number))
      (setq row-number (1+ row-number)))
    total))
(triangle 4)
(defun reverse-list-with-dolist (list)
  "Using dolist, reverse the order of LIST."
  (let (value)  ; make sure list starts empty
    (dolist (element list value)
      (setq value (cons element value)))))
(setq animals '(gazelle giraffe lion tiger))

(defun print-elements-recursively (list)
  "Print each element of LIST on a line of its own.
Uses recursion."
  (when list                            ; do-again-test
        (print (car list))              ; body
        (print-elements-recursively     ; recursive call
         (cdr list))))                 ; next-step-expression

(print-elements-recursively animals)
(defun square-each (numbers-list)
  "Square each of a NUMBERS LIST, recursively."
  (if (not numbers-list)                ; do-again-test
      nil
    (cons
     (* (car numbers-list) (car numbers-list))
     (square-each (cdr numbers-list))))) ; next-step-expression


(square-each '(1 2 3))
(defun add-elements (numbers-list)
  "Add the elements of NUMBERS-LIST together."
  (if (not numbers-list)
      0
    (+ (car numbers-list) (add-elements (cdr numbers-list)))))


(add-elements '(1 2 3 4))

(defun keep-three-letter-words (word-list)
  "Keep three letter words in WORD-LIST."
  (cond
   ;; First do-again-test: stop-condition
   ((not word-list) nil)

   ;; Second do-again-test: when to act
   ((eq 3 (length (symbol-name (car word-list))))
    ;; combine acted-on element with recursive call on shorter list
    (cons (car word-list) (keep-three-letter-words (cdr word-list))))

   ;; Third do-again-test: when to skip element;
   ;;   recursively call shorter list with next-step expression
   (t (keep-three-letter-words (cdr word-list)))))


(keep-three-letter-words '(one two three four five six))


(defun forward-sentence (&optional arg)
  "Move forward to next end of sentence.  With argument, repeat.
With negative argument, move backward repeatedly to start of sentence.

The variable `sentence-end' is a regular expression that matches ends of
sentences.  Also, every paragraph boundary terminates sentences as well."

  (interactive "p")
  (or arg (setq arg 1))
  (let ((opoint (point))
        (sentence-end (sentence-end)))
    (while (< arg 0)
      (let ((pos (point))
            (par-beg (save-excursion (start-of-paragraph-text) (point))))
       (if (and (re-search-backward sentence-end par-beg t)
                (or (< (match-end 0) pos)
                    (re-search-backward sentence-end par-beg t)))
           (goto-char (match-end 0))
         (goto-char par-beg)))
      (setq arg (1+ arg)))

    (while (> arg 0)
      (let ((par-end (save-excursion (end-of-paragraph-text) (point))))
       (if (re-search-forward sentence-end par-end t)
           (skip-chars-backward " \t\n")
         (goto-char par-end)))
      (setq arg (1- arg)))
    (constrain-to-field nil opoint t)))
(insert-rectangle '("first" "second" "third"))

first
second					      
third



;;; First version.
(defun column-of-graph (max-graph-height actual-height)
  "Return list of strings that is one column of a graph."
  (let ((insert-list nil)
        (number-of-top-blanks
         (- max-graph-height actual-height)))


    ;; Fill in asterisks.
    (while (> actual-height 0)
      (setq insert-list (cons "*" insert-list))
      (setq actual-height (1- actual-height)))


    ;; Fill in blanks.
    (while (> number-of-top-blanks 0)
      (setq insert-list (cons " " insert-list))
      (setq number-of-top-blanks
            (1- number-of-top-blanks)))


    ;; Return whole list.
    insert-list))
(column-of-graph 5 3)
;;; Line to top of window;
;;; replace three keystroke sequence  C-u 0 C-l
(defun line-to-top-of-window ()
  "Move the line that point is on to top of window."
  (interactive)
  (recenter 0))
(line-to-top-of-window)
(defun triangle-bugged (number)
  "Return sum of numbers 1 through NUMBER inclusive."
  (let ((total 0))
    (while (> number 0)
      (setq total (+ total number))
      (setq number (1= number)))      ; Error here.
    total))
(triangle-bugged 4)
giµ21E7

