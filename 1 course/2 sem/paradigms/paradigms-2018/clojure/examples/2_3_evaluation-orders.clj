(chapter "Evaluation Orders")
(example "Helpers"
         (defn indented [& xs]
           (apply println (cons "       " xs)))
         (defn list-concat [& xss]
           (apply list (apply concat xss)))
         (defn trace [x]
           (indented "trace" x)
           x))
(example "Applicative evaluation order"
         (defn add-app [a b]
           (indented "evaluate f")
           (+ a b))
         (add-app (trace 1) (trace 2))
         (let [v (trace 2)] (add-app v v)))
(example "Normal evaluation order"
         (defn add-norm [x y]
           (indented "evaluate f")
           (+ (eval x) (eval y)))
         (add-norm '(trace 1) '(trace 2))
         (let [v '(trace 2)] (add-norm v v)))
(example "Lazy evaluation order"
         (defn add-lazy [x y]
           (indented "evaluate f")
           (+ (force x) (force y)))
         (add-lazy (delay (trace 1)) (delay (trace 2)))
         (let [v (delay (trace 2))] (add-lazy v v)))
