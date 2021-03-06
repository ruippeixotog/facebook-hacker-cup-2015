# Facebook Hacker Cup 2015

This repository contains my solutions to the problems from [Facebook Hacker Cup 2015][1]. These solutions are provided "as is" - I give no guarantees that they will work as expected.

## Instructions

You can compile all the problems by issuing the following command:

    $ make

If you want to compile only a specific problem, issue the following command, replacing `<problem_id>` with the section and identifier of the problem you want to compile (see section "Problems Solved" for the list of possible identifiers):

    $ make <problem_id>

Running a compiled problem is just a matter of executing a command similar to the next one, replacing `<problem_id>` with the identifier of the desired problem:

    $ ./<problem_id>

Unless stated otherwise, every problem in this repository reads from the standard input and writes to the standard output.

## Problems Solved

The following is the list of the problems solved. Each problem identifier is specified between round brackets. Problems marked with ✓ are done, while problems with ✗ are not complete or aren't efficient enough for the problem's limits.

### Qualification Round

* ✓ [15: Cooking the Books][qual1] (`cooking-the-books`)
* ✓ [30: New Year's Resolution][qual2] (`new-years-resolution`)
* ✓ [55: Laser Maze][qual3] (`laser-maze`)

### Round 1

* ✓ [10: Homework][round11] (`homework`)
* ✓ [25: Autocomplete][round12] (`autocomplete`)
* ✓ [25: Winning at Sports][round13] (`winning-at-sports`)
* ✓ [40: Corporate Gifting][round14] (`corporate-gifting`)

### Round 2

* ✓ [10: Lazy Sort][round21] (`lazy-sort`)
* ✓ [20: All Critical][round22] (`all-critical`)
* ✓ [25: Autocomplete Strikes Back][round23] (`autocomplete-strikes-back`)
* ✓ [45: Fox Socks][round24] (`fox-socks`)

[1]: https://www.facebook.com/hackercup
[qual1]: https://www.facebook.com/hackercup/problems.php?pid=582062045257424&round=742632349177460
[qual2]: https://www.facebook.com/hackercup/problems.php?pid=1036037553088752&round=742632349177460
[qual3]: https://www.facebook.com/hackercup/problems.php?pid=1523599254559737&round=742632349177460
[round11]: https://www.facebook.com/hackercup/problems.php?pid=582396081891255&round=344496159068801
[round12]: https://www.facebook.com/hackercup/problems.php?pid=313229895540583&round=344496159068801
[round13]: https://www.facebook.com/hackercup/problems.php?pid=688426044611322&round=344496159068801
[round14]: https://www.facebook.com/hackercup/problems.php?pid=759650454070547&round=344496159068801
[round21]: https://www.facebook.com/hackercup/problem/193964420699886/
[round22]: https://www.facebook.com/hackercup/problem/1394490097513820/
[round23]: https://www.facebook.com/hackercup/problem/1525315704386390/
[round24]: https://www.facebook.com/hackercup/problem/1521672018093383/
