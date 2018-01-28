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


    <link rel="stylesheet" type="text/css" href="/teaching/s18-6550/css/latex.css"/>


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
Define a graph $G'$ which is otherwise identical to $G$ but for a new
weight function $w'_a = w_a - M_v$ for every $a \in \partial^+_v$;
this guarantees every vertex has an outgoing arc of weight $0$. it's
useful to think of $M_v$ as the weight that must be paid for any
arborescence to contain $v$. The next lemma states that this
tranformation doesn't change the problem in any real way.

<div class="lemma"> $T$ is a min-weight $r$-arborescence for $G$
$\Leftrightarrow$ $T$ is a min-weight $r$-arborescence for $G'$. </div>

Given the above lemma, we consider an algorithm that first includes
some $0$-weight arc out of each vertex $v$; if this is an arborescence
then it must be minimum weight. Otherwise, the resulting graph
contains several connected components, each of which has a directed
cycle (by a counting argument relating the number of edges and the
number of vertices). For any $0$-weight cycle $C$, we will contract
$C$ into a single node, removing arcs inside $C$ and replacing any
edges $(v, w)$ for $w\in C$ by the cheapest $(v,w') for $w'\in
C$. Call this graph $G''$.

<div class="claim"> Let $OPT(G)$ be the cost of the min-weight $r$-arborescence on $G$. Then $OPT(G') = OPT(G'')$. </div>

<div class="proof"> First, we show $OPT(G') \leq OPT(G'')$. Given an
arborescence for $G''$, some vertices correspond to cycles in
$G'$. Expand these cycles and drop some $0$-weight edge along each;
this is now an arborescence in $G'$ with the same weight as
$OPT(G'')$. The min-weight arborescence for $G'$ can only have smaller
weight.

Now, we show $OPT(G'') \leq OPT(G')$. Given a min-weight arborescence
$T'$ for $G'$, contracting $G'$ to $G''$ still connects all vertices
to the root in $G''$. Therefore, this graph still contains a superset
of the edges necessary to create an arborescence in $G''$.  </div>

This gives us an algorithm for computing arborescences: take all
$0$-weight edges in $G'$, contract all cycles this creates, then
recurse on $G''$; as $G''$ has strictly fewer vertices and edges than
$G'$, this is a well-founded recursion. Each contraction takes $O(m)$
time and there are at most $O(n)$ of them, so in total this takes
$O(mn)$ time. It's possible to implement this algorithm using better
datastructures (Tarjan [Tar77] used priority queues to improve the
runtime to $O(\min(m \log n, n^2))$ time, and Gabow, Galil, Spencer
and Tarjan [GGST86] give an algorithm to solve the min-cost
arborescence problem in $O(n \log n + m)$ time.