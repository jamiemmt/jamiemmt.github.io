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

<!-- <style type="text/css" src="/teaching/s18-6550/_layouts/latex.css"></script>-->

<script src="https://unpkg.com/mermaid@7.1.2/dist/mermaid.min.js"></script>
<script>mermaid.initialize({startOnLoad:true});</script>


  <style type="text/css">
    body {
    max-width: 80%;
    margin: 15em auto;
}
</style>
</head>


This post describes the generalization of computing minimum spanning
trees on undirected graphs to the setting of directed graphs. In this
setting, we refer to edges as ordered pairs rather than unordered
pairs, which are called <b> arcs </b> , a graph $G = (V, A)$ now
containing vertices $V$ and arcs or directed edges $A$. Suppose some
specific vertex $r\in V$ is denoted as the root of $G$.

<b> Definition 1 </b> <i> <b> ($r$ </b>- arborescence)</i> Given a
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
arborescence:

<div class="mermaid">
graph LR
r
C --3-->r
C --1-->A
A -- 4 --> r
</div>

since a greedy approach would take $(C, r)$ and then need to take both
$(c, a)$ and $(a,r)$ to complete the arborescence, at which point the
arc $(a,r)$ would be unnecessary. This example shows more generally
that basic greedy approaches to this problem won't work.

The algorithm that solves this problem is therefore more sophisticated
than in the undirected case. Chu-Liu [CL65], Edmonds [Edm67], and Bock
[Boc71] discovered this algorithm independently. We will follow Karp’s
description of Edmonds' algorithm.

The "boundary" edges of a vertex is usually denoted by $\partial_v$;
the set of edges leaving a vertex is denoted $\partial^+_v$, and the
edges entering a vertex is denoted $\partial^-_v$. This notation is
overloaded to also denote the set of edges entering or leaving a <i>
set </i> of vertices as well.

For a given vertex $v$, we'll keep track of the weight of the least
expensive edge leaving $v$: define $M_v = \min_{a \partial^+_v} w_a$.
Define a new weight function $w'_a = w_a - M_v$ for every $a \in
\partial^+_v$; this guarantees every vertex has an outgoing arc of
weight $0$. it's useful to think of $M_v$ as the weight that must be
paid for any arborescence to contain $v$. The next lemma states that this tranformation doesn't change the problem in any real way.

<div class="lemma">  $T$ is a min-weight $r$-arborescence for $(G,w)$ $\Leftrightarrow$
$T$ is a min-weight $r$-arborescence for $(G, w')$. </div>