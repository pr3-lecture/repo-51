(setq tree '(10 (5 (3) (7)) (13 (12) (20))))

(defun insert(tree val) 
 (cond ((< (first tree) val) 
        (cond ((null (nth 2 tree)) (list (first tree) (list NIL) (list val)))
              ((nth 2 tree)(list (first tree)(nth 1 tree)(insert (nth 2 tree) val))))) 
       ((> (first tree) val) 
        (cond ((null (nth 1 tree)) (list (first tree) (list val) (list NIL)))
              ((nth 1 tree)(list (first tree)(insert (nth 1 tree) val)(nth 2 tree)))))
     ))


(setq newTree (insert tree 22))
(print newTree)


(defun contains(tree val)
     (cond ((= (first tree) val) t)
           ((nth 1 tree)(contains (nth 1 tree) val))
           ((nth 2 tree)(contains (nth 2 tree) val))
           (T NIL)))

(print (contains tree 5))


(defun size(tree) (+ 1
    (cond  ((nth 1 tree)(size (nth 1 tree)))(T 0))
    (cond  ((nth 2 tree)(size (nth 2 tree)))(T 0))
))

(print (size newTree))


(defun getMin(tree)
    (cond  ((nth 1 tree)(getMin (nth 1 tree)))(T (first tree)))
 )

(print (getMin tree))


(defun getMax(tree)
    (cond  ((nth 2 tree)(getMax (nth 2 tree)))(T (first tree)))
 )

(print (getMax tree))
