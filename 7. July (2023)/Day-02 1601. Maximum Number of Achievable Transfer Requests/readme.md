
<!-- Heading -->
<h1> 1601. Maximum Number of Achievable Transfer Requests
 </h1>


<p style="color : rgba(255, 255, 255, 0.65);padding-bottom: 0.25rem; padding-top: 0.25rem;    padding-left: 0.625rem; padding-right: 0.625rem; display:inline; font-size: 1.25rem">Hard</p>
</br>

</br>
<!-- Tags -->
<p><b>Problem Tags : </b>
<code>Arrays</code>&nbsp;&nbsp;<code>
Enumeration</code>&nbsp;&nbsp;<code>Backtracking</code>&nbsp;&nbsp;<code>Bit Manipulation</code>&nbsp;&nbsp;<code>Bitmask</code></p>

</br>

<!-- Problem Statement -->
We have <code>n</code> buildings numbered from <code>0</code> to <code>n - 1</code>. Each building has a number of employees. It's transfer season, and some employees want to change the building they reside in.

You are given an array <code>requests</code> where <code>requests[i] = [fromi, toi]</code> represents an employee's request to transfer from building <code>from<sub>i</sub></code> to building <code>to<sub>i</sub></code>.

**All buildings are full**, so a list of requests is achievable only if for each building, the **net change in employee transfers is zero**. This means the number of employees **leaving** is **equal** to the number of employees **moving in**. For example if <code>n = 3</code> and two employees are leaving building <code>0</code>, one is leaving building <code>1</code>, and one is leaving building <code>2</code>, there should be two employees moving to building <code>0</code>, one employee moving to building <code>1</code>, and one employee moving to building <code>2</code>.

Return *the maximum number of achievable requests*.

<!-- line break -->
<p>&nbsp</p>

<!-- example 1 -->
<strong>Example 1:</strong>

![Alt text](move1.jpg)
<pre>
<strong>Input:</strong> n = 5, requests = [[0,1],[1,0],[0,1],[1,2],[2,0],[3,4]]
<strong>Output:</strong> 5
<strong>Explanation:</strong> Let's see the requests:
From building 0 we have employees x and y and both want to move to building 1.
From building 1 we have employees a and b and they want to move to buildings 2 and 0 respectively.
From building 2 we have employee z and they want to move to building 0.
From building 3 we have employee c and they want to move to building 4.
From building 4 we don't have any requests.
We can achieve the requests of users x and b by swapping their places.
We can achieve the requests of users y, a and z by swapping the places in the 3 buildings.
</pre>

<!-- example 2 -->
<strong>Example 2:</strong>

![Alt text](move2.jpg)
<pre>
<strong>Input:</strong> n = 3, requests = [[0,0],[1,2],[2,1]]
<strong>Output:</strong> 3
<strong>Explanation:</strong> Let's see the requests:
From building 0 we have employee x and they want to stay in the same building 0.
From building 1 we have employee y and they want to move to building 2.
From building 2 we have employee z and they want to move to building 1.
We can achieve all the requests.
</pre>

<!-- example 3 -->
<strong>Example 3:</strong>

<pre>
<strong>Input:</strong> n = 4, requests = [[0,3],[3,1],[1,2],[2,0]]
<strong>Output:</strong> 4
</pre>


<!-- line break -->
<p>&nbsp</p>


<!-- constraints -->
<strong>Constraints:</strong>
- <p><code>1 <= n <= 20</code></p>
- <p><code>1 <= requests.length <= 16</code><p>
- <p><code>requests[i].length == 2</code></p>
- <p><code>0 <= from<sub>i</sub>, to<sub>i</sub> < n</code></p>


<!-- line break -->
<p>&nbsp</p>


<!-- horizontal rule -->
<hr>


<!-- Links -->
<h3>Links :</h3>

- [Leetcode](https://leetcode.com/problems/maximum-number-of-achievable-transfer-requests/)
- [Leetcode Editorial](https://leetcode.com/problems/maximum-number-of-achievable-transfer-requests/editorial)
- [C++ Submission Link](https://leetcode.com/problems/maximum-number-of-achievable-transfer-requests/submissions/984650341/)

<hr>