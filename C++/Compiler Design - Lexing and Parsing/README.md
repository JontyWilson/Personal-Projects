##Goal##
Modify the `lexer_demo.cpp` to allow for the parsing of new expressions. 

Create an Intermediate Representation of these expressions in `lexer_demo_with_ir.cpp`.

Create object code to an external C library (`lexer_with_ir_and_object_code.cpp`) and driver code (`lexer_with_ir_and_object_code_driver.cpp`) to test the new functions: testLogicalAnd(), testLogicalOr(), and testLogicalXor().

expressions: 
- division: `/`
- OR: `|`
- AND: `&`
- XOR: `^`
- Logic command: `logic`


##Outcome##

**Expressions**
- division: `/`
![alt text](image.png)

- OR: `|`
![alt text](image-1.png)

- AND: `&`
![alt text](image-2.png)

- XOR: `^`
![alt text](image-3.png)

- Logic command: `logic`
![alt text](image-4.png)

**Intermediate Representation**
- division: `/`
![alt text](image-5.png)

- OR: `|`
![alt text](image-6.png)

- AND: `&`
![alt text](image-7.png)

- XOR: `^`
![alt text](image-8.png)


**Function Driver & Object Code test**

![alt text](image-9.png)



