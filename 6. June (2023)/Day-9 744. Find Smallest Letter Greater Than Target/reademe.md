
<!-- Heading -->
<h1> 744. Find Smallest Letter Greater Than Target
 </h1>


<p style="color : rgba(255, 255, 255, 0.65);padding-bottom: 0.25rem; padding-top: 0.25rem;    padding-left: 0.625rem; padding-right: 0.625rem; display:inline; font-size: 1.25rem">Easy</p>
</br>

</br>
<!-- Tags -->
<p><b>Problem Tags : </b>
<code>Arrays</code>&nbsp;&nbsp;<code>Binary Search</code><p>

</br>

<!-- Problem Statement -->
You are given an array of characters <code>letters</code> that is sorted in **non-decreasing order**, and a character <code>target</code>. There are **at least two different** characters in <code>letters</code>.

Return *the smallest character* in <code>letters</code> that is *lexicographically greater than* <code>target</code>. If such a character does not exist, return the first character in <code>letters</code>.

<!-- line break -->
<p>&nbsp</p>

<!-- example 1 -->
<strong>Example 1:</strong>
<pre>
<strong>Input:</strong> letters = ["c","f","j"], target = "a"
<strong>Output:</strong> "c"
<strong>Explanation:</strong> The smallest character that is lexicographically greater than 'a' in letters is 'c'.
</pre>

<!-- example 2 -->
<strong>Example 2:</strong>
<pre>
<strong>Input:</strong> letters = ["c","f","j"], target = "c"
<strong>Output:</strong> "f"
<strong>Explanation:</strong> The smallest character that is lexicographically greater than 'c' in letters is 'f'.
</pre>

<!-- example 3 -->
<strong>Example 3:</strong>
<pre>
<strong>Input:</strong> letters = ["x","x","y","y"], target = "z"
<strong>Output:</strong> "x"
<strong>Explanation:</strong> There are no characters in letters that is lexicographically greater than 'z' so we return letters[0].
</pre>


<!-- line break -->
<p>&nbsp</p>


<!-- constraints -->
<strong>Constraints:</strong>
- <p><code>2 <= letters.length <= 10<sup>4</sup></code></p>
- <p><code>letters[i]</code> is a lowercase English letter.</p>
- <p><code>letters</code> is sorted in non-decreasing order.</p>
- <p><code>letters</code> contains at least two different characters.</p>
- <p><code>target</code> is a lowercase English letter.</p>



<!-- line break -->
<p>&nbsp</p>


<!-- horizontal rule -->
<hr>


<!-- Links -->
<h3>Links :</h3>

- [Leetcode](https://leetcode.com/problems/find-smallest-letter-greater-than-target/)
- [Submission Link](https://leetcode.com/problems/find-smallest-letter-greater-than-target/submissions/967145273/)

<hr>