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

       <script type="text/javascript" src="//cdnjs.cloudflare.com/ajax/libs/marked/0.2.9/marked.min.js"></script>

<script src="https://unpkg.com/mermaid@7.1.2/src/mermaid.js"></script>
<script>mermaid.initialize({startOnLoad:true});</script>

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


So, an arborescence contains a directed path from every vertex to the
root $r$. A <b> minimum-cost $r$-arborescence</b> is just an
$r$-arborescence that has the smallest weight according to a weight
function $w : A \to \mathbb{R}$. Note that running a depth-first
search from the root on the reversed set of arcs in $G$ makes it easy
to check if it contains an $r$-arborescence.


We'd like to find a (fast) algorithm for computing minimum-weight
arborescences. The MST problem had lots of nice properties, and it's
natural to ask if some of those extend to this problem as well. In
particular, the cut and cycle rules mean one can greedily add and
remove certain edges from a graph when constructing a MST; greedy
algorithms generally work for the MST problem. For the min-cost
$r$-arborescence problem, an analogous greedy building up would add
the min-weight arc into the connected component containing $r$ in each
round. However, that won't necessarily result in an optimal
arborescence.

<div class="mermaid">
graph LR
      A --- B
      B-->C[fa:fa-ban forbidden]
      B-->D(fa:fa-spinner);
</div>