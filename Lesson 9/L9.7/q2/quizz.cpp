/*
 Quizz 1:
 For each subitem, answer “yes”, “no”, or “possibly” to whether the action described will result in 
    undefined behavior (immediately). 
 If the answer is “possibly”, clarify when.
*/

2a) Assigning a new address to a pointer:
   no

2b) Assigning nullptr to a pointer:
   no

2c) Dereferencing a pointer to a valid object:
   no

2d) Dereferencing a dangling pointer:
   yes

2e) Dereferencing a null pointer:
   yes

2f) Dereferencing a non-null pointer:
   possibly, if pointer is dangling from a destroyed variable