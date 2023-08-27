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
