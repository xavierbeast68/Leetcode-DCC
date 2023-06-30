
<!-- Heading -->
<h1> 864. Shortest Path to Get All Keys
 </h1>


<p style="color : rgba(255, 255, 255, 0.65);padding-bottom: 0.25rem; padding-top: 0.25rem;    padding-left: 0.625rem; padding-right: 0.625rem; display:inline; font-size: 1.25rem">Hard</p>
</br>

</br>
<!-- Tags -->
<p><b>Problem Tags : </b>
<code>Arrays</code>&nbsp;&nbsp;<code>Bit Manipulation</code>&nbsp;&nbsp;<code>Breadth-First Search</code>&nbsp;&nbsp;<code>Matrix</code></p>

</br>

<!-- Problem Statement -->
You are given an <code>m x n</code> grid <code>grid</code> where:
<ul>
<li><code>'.'</code> is an empty cell.</li>
<li><code>'#'</code> is a wall.</li>
<li><code>'@'</code> is the starting point.</li>
<li>Lowercase letters represent keys.</li>
<li>Uppercase letters represent locks.</li>
</ul>
You start at the starting point and one move consists of walking one space in one of the four cardinal directions. You cannot walk outside the grid, or walk into a wall.

If you walk over a key, you can pick it up and you cannot walk over a lock unless you have its corresponding key.

For some <code>1 <= k <= 6</code>, there is exactly one lowercase and one uppercase letter of the first <code>k</code> letters of the English alphabet in the grid. This means that there is exactly one key for each lock, and one lock for each key; and also that the letters used to represent the keys and locks were chosen in the same order as the English alphabet.

Return the lowest number of moves to acquire all keys. If it is impossible, return <code>-1</code>.

<!-- line break -->
<p>&nbsp</p>

<!-- example 1 -->
<strong>Example 1:</strong>

![Alt text](lc-keys2.jpg)
<pre>
<strong>Input:</strong> grid = ["@.a..","###.#","b.A.B"]
<strong>Output:</strong> 8
<strong>Explanation:</strong> Note that the goal is to obtain all the keys not to open all the locks.
</pre>

<!-- example 2 -->
<strong>Example 2:</strong>

![Alt text](lc-key2.jpg)
<pre>
<strong>Input:</strong> grid = ["@..aA","..B#.","....b"]
<strong>Output:</strong> 6
</pre>

<!-- example 3 -->
<strong>Example 3:</strong>

![Alt text](lc-keys3.jpg)
<pre>
<strong>Input:</strong> grid = ["@Aa"]
<strong>Output:</strong> -1
</pre>


<!-- line break -->
<p>&nbsp</p>


<!-- constraints -->
<strong>Constraints:</strong>
- <p><code>m == grid.length</code></p>
- <p><code>n == grid[i].length</code></p>
- <p><code>1 <= m, n <= 30</code></p>
- <p><code>grid[i][j]</code> is either an English letter, <code>'.'</code>, <code>'#'</code>, or <code>'@'</code>.</p>
- The number of keys in the grid is in the range <code>[1, 6]</code>.
- Each key in the grid is **unique**.
- Each key in the grid has a matching lock.

<!-- line break -->
<p>&nbsp</p>


<!-- horizontal rule -->
<hr>


<!-- Links -->
<h3>Links :</h3>

- [Leetcode](https://leetcode.com/problems/shortest-path-to-get-all-keys/)
- [Submission Link](https://leetcode.com/problems/shortest-path-to-get-all-keys/submissions/982494053/)

<hr>