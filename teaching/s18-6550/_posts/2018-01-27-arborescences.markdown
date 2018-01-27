---
title: Moving From Undirected to Directed Graphs, MSTs to Arborescences
layout: post
---


<head>

<script src='https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.2/MathJax.js?config=TeX-MML-AM_CHTML'></script>
<script type="text/x-mathjax-config">
MathJax.Hub.Config({
  tex2jax: {inlineMath: [['$','$'], ['\\(','\\)']]}
});
</script>
<script type="text/javascript" async src="path-to-mathjax/MathJax.js?config=TeX-AMS_CHTML"></script>

       <script type="text/javascript" src="//cdnjs.cloudflare.com/ajax/libs/marked/0.2.9/marked.min.js"></script>

</head>


This post describes the generalization of computing minimum spanning
trees on undirected graphs to the setting of directed graphs. In this
setting, we refer to edges as ordered pairs rather than unordered
pairs, which are called <b> arcs </b> , a graph $G = (V, A)$ now
containing vertices $V$ and arcs or directed edges $A$. Suppose some
specific vertex $r\in V$ is denoted as the root of $G$.

<b> Definition 1 </b> <i> <b> $r$ </b>- arborescence</i> Given a
graph $G = (V, A)$ with root $r$, and $r$-arborescence is a set of
arcs $A'\subseteq A$ such that for every $v\in V$:

* There is some $(v, v') \in A'$
* There is a directed path from $v$ to $r$ using only arcs in $A'$.

