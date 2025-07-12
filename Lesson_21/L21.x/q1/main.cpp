/*
 Quizz 1:

 Assuming Point is a class and point is an instance of that class, should you use a normal/friend or 
 member function overload for the following operators?
*/

// a) point + point
// A: + is binary operator not modifying left operand, should use normal/friend function  

// b) -point
// A: - is unary operator, doesnt take any parameters (uses *this) so best done as member function

// c) std::cout << point
// A: << is binary operator modifying left operand (e.g std::ostream& out), but cant add a member function of
// left operand class (STL std::ostream), best done as normal/friend function

// d) point = 5;
// A: = is binary operator modifying left operand and member function can be added, member function is
// the correct solution