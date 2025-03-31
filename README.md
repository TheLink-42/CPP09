<div align="center">

![CPP](https://github.com/TheLink-42/42-project-badges/blob/main/badges/cppm.png)

# 42 CPP09

**This project from School 42 aims to get students acquainted with the C++ STL containers.
The project consists of three exercises that need to be solved using different containers.**


</div>

---

## Bitcoin Exchange (Exercise 00)

Create a program that outputs the value of a certain amount of Bitcoin on a certain date.
It must use a database in csv format representing Bitcoin price over time.
The program will take a second database as input which containes the desired dates and amount of Bitcoin to exchange.
 
**Rules to follow:**
* Program name must be btc.
* Must take the input file as an argument.
* Input file must follow the format "date | amount".
* Dates must follow the format: Year-Month-Day
* Amount must be float or positive integer, between 0-100.
* Result must be displayed on the standard output follwing the format: 
	"date => amount = value".
* If a date does not exist on your DB you must use the closest date on your DB (lower).
* Handle possible errors with appropriate error messages.

**Chosen container:**
* std::map

---

## Reverse Polish Notation (Exercise 01)

Create a program that outputs the result of a reversed Polish mathematical expression.

**Rules to follow:**
* Program name must be RPN.
* Must take an inverted Polish mathematical expression as an argument.
* Numbers used and passed as arguments will always be less than 10.
* Result must be displayed on the standard output.
* Must be able to handle operations with these tokens "+ - / *".
* No need to manage brackets or decimal numbers.
* Handle possible errors with appropriate error messages.

**Chosen container:**
* std::stack

---

## PmergeMe (Exercise 02)

Create a program that sorts a set of positive integers using the merge-insertion sort algorithm,
also known as Ford-Johnson algorithm.

**Rules to follow:**
* Program name must be PmergeMe.
* Must take a positive integer sequence as argument.
* Must display the output with the following format:
	* First line: "Before: [unsorted sequence of integers]"
	* Second line: "After: [sorted sequence of integers]"
	* Third line: "Time to process a range of [number of elements] elements with [first container]: [time taken]"
	* Fourth line: "Time to process a range of [number of elements] elements with [second container]: [time taken]"
* Handle possible errors with appropriate error messages.

**Chosen containers:**
* std::vector
* std::deque

---

## Contact

If you have any questions feel free to reach out!

* **Github:** [TheLink-42](https://github.com/TheLink-42)
* **Slack:** [jbaeza-c](https://42born2code.slack.com/team/U05RS80818A)
* **LinkedIn:** [Jaime Baeza Casado](https://www.linkedin.com/in/jaime-baeza-casado-892684327/)

---

Check other projects [here](https://github.com/TheLink-42/42-Journey)
