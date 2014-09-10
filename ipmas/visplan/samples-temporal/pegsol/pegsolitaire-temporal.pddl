;; Peg Solitaire domain

(define (domain pegsolitaire-temporal)
    (:requirements :typing :durative-actions)
    (:types location - object)
    (:predicates
        (IN-LINE ?x ?y ?z - location)
        (occupied ?l - location)
        (free ?l - location)
    )

    (:durative-action jump
     :parameters (?from - location ?through - location ?to - location)
     :duration (= ?duration 1)
     :condition (and 
                    (over all (IN-LINE ?from ?through ?to))
                    (at start (occupied ?from))
                    (at start (occupied ?through))
                    (at start (free ?to))
                )
     :effect (and
                 (at start (not (occupied ?from)))
                 (at start (not (occupied ?through)))
                 (at start (not (free ?to)))
                 (at end (free ?from))
                 (at end (free ?through))
                 (at end (occupied ?to))
             )
    )
)
