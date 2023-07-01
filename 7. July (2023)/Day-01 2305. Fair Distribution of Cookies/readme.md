
<!-- Heading -->
<h1> 2305. Fair Distribution of Cookies
 </h1>


<p style="color : rgba(255, 255, 255, 0.65);padding-bottom: 0.25rem; padding-top: 0.25rem;    padding-left: 0.625rem; padding-right: 0.625rem; display:inline; font-size: 1.25rem">Medium</p>
</br>

</br>
<!-- Tags -->
<p><b>Problem Tags : </b>
<code>Arrays</code>&nbsp;&nbsp;<code>
Dynamic Programming</code>&nbsp;&nbsp;<code>Backtracking</code>&nbsp;&nbsp;<code>Bit Manipulation</code>&nbsp;&nbsp;<code>Bitmask</code>&</p>

</br>

<!-- Problem Statement -->
You are given an integer array <code>cookies</code>, where <code>cookies[i]</code> denotes the number of cookies in the <code>ith</code> bag. You are also given an integer <code>k</code> that denotes the number of children to distribute **all** the bags of cookies to. All the cookies in the same bag must go to the same child and cannot be split up.

The **unfairness** of a distribution is defined as the **maximum total** cookies obtained by a single child in the distribution.

Return the **minimum** unfairness of all distributions.

<!-- line break -->
<p>&nbsp</p>

<!-- example 1 -->
<strong>Example 1:</strong>

<pre>
<strong>Input:</strong> cookies = [8,15,10,20,8], k = 2
<strong>Output:</strong> 31
<strong>Explanation:</strong> One optimal distribution is [8,15,8] and [10,20]
- The 1st child receives [8,15,8] which has a total of 8 + 15 + 8 = 31 cookies.
- The 2nd child receives [10,20] which has a total of 10 + 20 = 30 cookies.
The unfairness of the distribution is max(31,30) = 31.
It can be shown that there is no distribution with an unfairness less than 31.
</pre>

<!-- example 2 -->
<strong>Example 2:</strong>

<pre>
<strong>Input:</strong> cookies = [6,1,3,2,2,4,1,2], k = 3
<strong>Output:</strong> 7
<strong>Explanation:</strong> One optimal distribution is [6,1], [3,2,2], and [4,1,2]
- The 1st child receives [6,1] which has a total of 6 + 1 = 7 cookies.
- The 2nd child receives [3,2,2] which has a total of 3 + 2 + 2 = 7 cookies.
- The 3rd child receives [4,1,2] which has a total of 4 + 1 + 2 = 7 cookies.
The unfairness of the distribution is max(7,7,7) = 7.
It can be shown that there is no distribution with an unfairness less than 7.
</pre>


<!-- line break -->
<p>&nbsp</p>


<!-- constraints -->
<strong>Constraints:</strong>
- <p><code>2 <= cookies.length <= 8</code></p>
- <p><code>1 <= cookies[i] <= 10<sup>5</sup></code><p>
- <p><code>2 <= k <= cookies.length</code></p>


<!-- line break -->
<p>&nbsp</p>


<!-- horizontal rule -->
<hr>


<!-- Links -->
<h3>Links :</h3>

- [Leetcode](https://leetcode.com/problems/fair-distribution-of-cookies/)
- [Leetcode Editorial](https://leetcode.com/problems/fair-distribution-of-cookies/editorial)
- [C++ Submission Link](https://leetcode.com/problems/fair-distribution-of-cookies/submissions/983528941/)
- [Java Submission Link](https://leetcode.com/problems/fair-distribution-of-cookies/submissions/983531401/)


<hr>