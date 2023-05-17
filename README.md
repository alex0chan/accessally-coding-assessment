
# AccessAlly Coding Assessment

### Guidelines

Thank you for your interest in the Full Stack Engineer role at AccessAlly! We are excited to move forward with you as a candidate in the interview process.

Please solve the coding problems below using the following guidelines:

1. Programming language: Please use C / C++, Java, Javascript, Python, PHP. If there is another language that you want to use, please confirm with us before start coding.
2. Program input: The program can accept input via command line, reading a file via a file name argument or through HTML element.
3. Program output: Write to command line or display in HTML.
4. What to send us: Source code file(s) for each problem.
If you have any questions along the way, please feel free to reach out: kathryn@accessally.com.

### Problem 1: Finding Favorite Times

**Problem Description**

Wendy has an LED clock radio, which is a 12-hour clock, displaying times from 12:00 to 11:59. The hours do not have leading zeros but minutes may have leading zeros, such as 2:07 or 11:03.

When looking at her LED clock radio, Wendy likes to spot arithmetic sequences in the digits. For example, the times 12:34 and 2:46 are some of her favourite times, since the digits form an arithmetic sequence.

A sequence of digits is an arithmetic sequence if each digit after the first digit is obtained by adding a constant common difference. For example, 1,2,3,4 is an arithmetic sequence with a common difference of 1, and 2,4,6 is an arithmetic sequence with a common difference of 2.

Suppose that we start looking at the clock at noon (that is, when it reads 12:00) and watch the clock for some number of minutes. How many instances are there such that the time displayed on the clock has the property that the digits form an arithmetic sequence?

**Input Specification**

The input contains one integer D (0 ≤ D ≤ 1 000 000 000), which represents the duration that the clock is observed. For 4 of the 15 available marks, D ≤ 10 000.

**Output Specification**

Output the number of times that the clock displays a time where the digits form an arithmetic sequence starting from noon (12:00) and ending after D minutes have passed, possibly including the ending time.

**Sample Input 1**

34

**Output for Sample Input 1**

1

**Explanation of Output for Sample Input 1**

Between 12:00 and 12:34, there is only the time 12:34 for which the digits form an arithmetic sequence.

**Sample Input 2**

180

**Output for Sample Input 2**

11

**Explanation of Output for Sample Input 2**

Between 12:00 and 3:00, the following times form arithmetic sequences in their digits (with the difference shown:

- 12:34 (difference 1),
- 1:11 (difference 0),
- 1:23 (difference 1),
- 1:35 (difference 2),
- 1:47 (difference 3),
- 1:59 (difference 4),
- 2:10 (difference -1),
- 2:22 (difference 0),
- 2:34 (difference 1),
- 2:46 (difference 2),
- 2:58 (difference 3).

### Problem 2: Blood Distribution

**Problem Description**

At the Cardiac Center there are four types of blood available: O, A, B, and AB. Each of these types of blood has an Rh factor, which is either “positive” or “negative”. There are many patients who each require 1 unit of blood. Each patient’s blood type determines the type of blood s/he may receive:

- Each Type O patient requires Type O blood.
- Each Type A patient may receive blood of Type A or Type O.
- Each Type B patient may receive blood of Type B or Type O.
- The Type AB patients may receive blood of any type.
- Patients who have Rh-negative blood can accept Rh-negative blood only, but patients with Rh-positive blood can accept either Rh-positive or Rh-negative types of blood.

We want as many patients as possible to receive a unit of blood. What is the maximum number of patients that can receive blood?

**Input Specification**

The first line of input contains 8 integers: the number of units of blood of Type O negative, O positive, A negative, A positive, B negative, B positive, AB negative and AB positive. This is followed by a line containing eight numbers: the number of patients whose blood type is O negative, O positive, A negative, A positive, B negative, B positive, and AB negative and AB positive. Each of these integers will be at least 0 and less than 107.

**Output Specification**

The output of your program should be a single number: the maximum number of patients that can receive blood.

**Sample Input**

5 5 3 1 2 11 5 12

2 4 9 2 3 9 7 3

**Output for Sample Input**

33

**An Explanation**

- 2 Type O- patients receive Type O- blood 9
- 4 Type O+ patients receive Type O+ blood
- 3 Type A- patients receive Type A- blood
- 3 Type A- patients receive Type 0- blood
- 1 Type A+ patients receive Type A+ blood
- 1 Type A+ patients receive Type O+ blood
- 2 Type B- patients receive Type B- blood
- 9 Type B+ patients receive Type B+ blood
- 5 Type AB- patient receives Type AB- blood
- 3 Type AB+ patients receive Type AB+ blood

**Note**: At least 30% of the test cases for this problem will have at most 1000 units of each type of blood.
