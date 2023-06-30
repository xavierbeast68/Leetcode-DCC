
<!-- Heading -->
<h1> 1970. Last Day Where You Can Still Cross
 </h1>


<p style="color : rgba(255, 255, 255, 0.65);padding-bottom: 0.25rem; padding-top: 0.25rem;    padding-left: 0.625rem; padding-right: 0.625rem; display:inline; font-size: 1.25rem">Hard</p>
</br>

</br>
<!-- Tags -->
<p><b>Problem Tags : </b>
<code>Arrays</code>&nbsp;&nbsp;<code>Binary Search</code>&nbsp;&nbsp;<code>Breadth-First Search</code>&nbsp;&nbsp;<code>Matrix</code>&nbsp;&nbsp;<code>Depth-First Search</code>&nbsp;&nbsp;<code>Union Find
</code></p>

</br>

<!-- Problem Statement -->
There is a 1-based binary matrix where <code>0</code> represents land and <code>1</code> represents water. You are given integers <code>row</code> and <code>col</code> representing the number of rows and columns in the matrix, respectively.

Initially on day <code>0</code>, the **entire** matrix is **land**. However, each day a new cell becomes flooded with **water**. You are given a **1-based** 2D array <code>cells</code>, where <code>cells[i] = [ri, ci]</code> represents that on the <code>ith</code> day, the cell on the <code>r<sub>i</sub>th</code> row and <code>c<sub>i</sub>th</code> column (**1-based** coordinates) will be covered with **water** (i.e., changed to <code>1</code>).

You want to find the **last** day that it is possible to walk from the **top** to the **bottom** by only walking on land cells. You can start from **any** cell in the top row and end at **any** cell in the bottom row. You can only travel in the **four** cardinal directions (left, right, up, and down).

Return the **last** day where it is possible to walk from the **top** to the **bottom** by only walking on land cells.

<!-- line break -->
<p>&nbsp</p>

<!-- example 1 -->
<strong>Example 1:</strong>

![Alt text](https://assets.leetcode.com/uploads/2021/07/27/1.png)
<pre>
<strong>Input:</strong> row = 2, col = 2, cells = [[1,1],[2,1],[1,2],[2,2]]
<strong>Output:</strong> 2
<strong>Explanation:</strong> The above image depicts how the matrix changes each day starting from day 0.
The last day where it is possible to cross from top to bottom is on day 2.
</pre>

<!-- example 2 -->
<strong>Example 2:</strong>

![Alt text](https://assets.leetcode.com/uploads/2021/07/27/2.png)
<pre>
<strong>Input:</strong> row = 2, col = 2, cells = [[1,1],[1,2],[2,1],[2,2]]
<strong>Output:</strong> 1
<strong>Explanation:</strong> The above image depicts how the matrix changes each day starting from day 0.
The last day where it is possible to cross from top to bottom is on day 1.
</pre>

<!-- example 3 -->
<strong>Example 2:</strong>

![Alt text](https://assets.leetcode.com/uploads/2021/07/27/3.png)
<pre>
<strong>Input:</strong> row = 3, col = 3, cells = [[1,2],[2,1],[3,3],[2,2],[1,1],[1,3],[2,3],[3,2],[3,1]]
<strong>Output:</strong> 3
<strong>Explanation:</strong> The above image depicts how the matrix changes each day starting from day 0.
The last day where it is possible to cross from top to bottom is on day 3.
</pre>


<!-- line break -->
<p>&nbsp</p>


<!-- constraints -->
<strong>Constraints:</strong>
- <p><code>2 <= row, col <= 2 * 10<sup>4</sup></code></p>
- <p><code>4 <= row * col <= 2 * 10<sup>4</sup></code></p>
- <p><code>cells.length == row * col</code></p>
- <p><code>1 <= r<sub>i</sub> <= row</code></p>
- <p><code>1 <= c<sub>i</sub> <= col</code></p>
- <p>All the values of <code>cells</code> are **unique**.</p>

<!-- line break -->
<p>&nbsp</p>


<!-- horizontal rule -->
<hr>


<!-- Links -->
<h3>Links :</h3>

- [Leetcode](https://leetcode.com/problems/last-day-where-you-can-still-cross/)
- [Leetcode Editorial](https://leetcode.com/problems/last-day-where-you-can-still-cross/editorial)
- [Submission Link](https://leetcode.com/problems/last-day-where-you-can-still-cross/submissions/983318394/)

<hr>