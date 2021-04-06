---
layout: page
title: Issues of Equity in High-Stakes targeted advertising
style: assets/blog.html
permalink: blog.html
---


# Ensuring equity in online advertising for employment, housing, and credit

by [Jamie Morgenstern](http://jamiemorgenstern.com), assistant professor in the Paul G. Allen School of Computer Science and Engineering at the University of Washington.

**Online advertising** systems have received a great deal of recent
scrutiny regarding their systems' displaying of high-stakes
advertisements to different demographic groups at wildly different
rates.  Examples include advertising for high-wage jobs being served
to men at higher rates than women [1], arrest record search sites
being shown at higher rates when searching for black-identifying names
than white-identifying names [2], showing financial advertisements
less often to older users [3], and showing housing advertisements in a
way which strongly correlated with protected categories such as sex,
family status, disability, national origin, and other protected
characteristics [4,5,6]. Some of these systems explicitly allow
advertisers to name demographics they want to see (or not see) their
ads and some allow the advertisers to select their audience based on
behavior on the platform or elsewhere online.

Platforms which do not allow advertisers to explicitly target
demographic groups can still allow intentional or unintentional
*redlining:* a user's behavior or information on a platform can be
strongly correlated with their demographics. Thus, removing explicit
demographic targeting from online advertising will not necessarily
ensure users from different demographics will see an ad with equal
frequency.

Even when platforms allow *no* targeting for advertisements in a given
domain (say, for example, housing advertisements), the ability of
*other* advertisers in possibly lower-stakes industries to target can
still lead to housing advertisements being shown at wildly different
rates to different demographics.

To give a very simple example of how this might occur, suppose that an
advertiser with a campaign selling running shoes targets people
between the ages of 25 and 40 who the platform identified as
women. This advertiser might be willing to pay $.10 for each time the
platform displays this shoe ad to someone in this slice of their user
base, and $.02 for the platform displaying it to anyone else. Suppose
a landlord with a new apartment building might want to advertise in
the same timeframe as the shoe company. They might be willing to pay
$.05 for each person who sees their ad.  Assume the advertising
platform shows each user a single ad, and chooses to show the one
which would pay more for their impression. This will result in
targeted people seeing ads from the shoe company, and un-targeted
people seeing ads for the new apartment building. So, the willingness
of a retail company to pay more to show their advertisement to certain
demographics results in that demographic seeing fewer housing
advertisements.

Many of the worrisome examples outlined here belong to industries with
higher than normal legal scrutiny regarding how the industries'
practices reach people from different demographics. The Civil Rights
Act provides extra tools to address unequal access to organizations
involved in voting, education, public accommodations, and
employment. The Equal Credit Opportunity Act provides similar levers
in the context of consumer lending. Unfortunately, legal avenues are
usually very slow in their ability to affect change, and technologies
which underly personalization systems are rapidly evolving.
*Therefore, relying on our legal system to "sort out" which forms of
personalized advertisements are legal and which are not is unlikely to
reduce the differing rates at which impactful advertisements are shown
to different demographics.*

**What, then, can we do about targeted advertising systems to ensure
ads which are "high-stakes" are shown to every demographic equally?**
As outlined above, it is not sufficient to ensure that high-stakes
advertisements are not given the ability to explicitly target
demographic groups, as these groups can be uncovered with targeting
through other characteristics. It is also not sufficient to remove
*all* targeting from high-stakes advertisers, as in most existing
systems, these advertisers will still need to compete with advertisers
who can target.  In my opinion, the only remaining possible
intervention which works within existing targeted advertising
frameworks is to:

1.  **Announce the percentage of advertisements which will be allocated to housing, to lending, and to employment that each person using a system will be served**, and then
2. **Categorize every advertisement as either pertaining to housing, lending, employment, or instead some category which allows targeting** (advertisements for sneakers, for example, might strike most people as an acceptable place for targeting leading to some demographics seeing such ads at higher rates than others). Finally,
3. **Run separate ad markets for each of these categories, and do zero targeting within the categories of housing, lending, and employment.** 

This shift, from every advertising opportunity being available to
every advertiser willing to pay enough, will ensure, *no matter how
advertisers behave once categorized*, that these high-stakes ads will
be shown to each demographic equally. It will still allow for
companies who see large revenue streams stemming from targeted
advertisement to capitalize on that revenue, in the domains where such
targeting is considered acceptable. ****

# How much revenue might advertising platforms lose with this approach?

**A quick analysis suggests the revenue lost in thinning the market
this way should be quite manageable, and possibly nonexistent,
depending upon what targeting high-stakes advertisers were allowed in
the unified market.**

Suppose a platform has 5% of its advertisers who place housing
advertisements. These advertisers contribute to the revenue of the
platform in two ways. First, they purchase some ad slots from the
company. Second, even for advertisements they ultimately do not buy,
they compete with other advertisers, driving up the price of those
advertisements.

*How much revenue must be lost to each of these sources?* 

For those impressions that housing advertisers won in the unified
market, revenue can be lost where non-housing advertisers provided
competition and drove up the housing advertisement prices. If this
competition was *untargeted*, then this can be replaced with effective
setting of reserve prices, resulting in little or no revenue loss. If
the competition was *targeted* to 10% of the population*,* this can
*still* be recovered by randomly setting reserve prices on 10% of the
housing ad slots. The only revenue that cannot effectively be
recovered using reserves comes from settings where some housing
advertiser was targeting and willing to pay more for certain
populations than others.  So, some revenue is lost if the comparison
is done to a system which allows housing advertisers to target, but
none is lost compared to one where housing ads cannot target.

For ads which housing advertisers lost but drove up prices, a similar
analysis can be done— cleverly set reserve prices can "mimic" the
competition the housing advertiser provided.  This could even be done
in a targeted, demographically dependent way, since the advertisements
in this segment are only advertising target-appropriate content. So,
the ads in the targeted segment of the market can generate at least as
much revenue as they did in the unified market.

# What other concerns does the proposed "segmented" market for advertisments raise?

If we shift from a completely unified market for advertisements to one
where 10% of all advertisments are preordained as "untargetable"
impressions for high-stakes ads, what additional impacts might this
have? The primary one, from my perspective, is that it will lead to a
necessary decisions about which ads are untargetable and which are
targetable. Who will make this determination?

If the advertisers self-identify, they will do so in a way to maximize
their utility. This may or may not lead them to truthfully report
whether their advertisement pertains to, say, housing. If it is
sufficiently profitable for them to target, they will report their ad
belongs to a targetable segment; if it is profitable enough for them
to not target but pay possibly lower prices in the untargeted market,
they will prefer that. Equitable display of untargeted categories will
not be affected by targetable ads behaving as untargetable, though it
will reduce the rate at which anyone sees untargetable categories. On
the other hand, untargetable ads such as housing ads might have
considerable incentive to target, and in targeting may very well
create inequity in display of housing advertisements. Advertisers who
categorize their own ads as targetable, then, will need to be audited
by either the platform or some external system to ensure such ads do
not pertain to some untargetable category.

```latex
[1]@article{datta2014automated,
  title={Automated experiments on ad privacy settings: A tale of opacity, choice, and discrimination},
  author={Datta, Amit and Tschantz, Michael Carl and Datta, Anupam},
  journal={arXiv preprint arXiv:1408.6491},
  year={2014}
}
[2] @article{sweeney2013discrimination,
  title={Discrimination in online ad delivery},
  author={Sweeney, Latanya},
  journal={Communications of the ACM},
  volume={56},
  number={5},
  pages={44--54},
  year={2013},
  publisher={ACM New York, NY, USA}
}

[4] https://nationalfairhousing.org/facebook-complaint/
[5] https://www.propublica.org/article/facebook-advertising-discrimination-housing-race-sex-national-origin
[6] https://www.propublica.org/article/facebook-lets-advertisers-exclude-users-by-race
```
