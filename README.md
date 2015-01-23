# Solutions to Facebook Hacker Cup 2015 problems

This repository contains solutions to the [Facebook Hacker Cup 2015][1] problems. These solutions are provided "as is". I give no guarantees that they will work as expected.

## Instructions

You can compile all the problems by issuing the following command:

    $ make

If you want to compile only a specific problem, issue the following command, replacing `<problem_id>` with the section and id of the problem you want to compile (see section "Problems Solved" for the list of possible ids):

    $ make <problem_id>

Running a compiled problem is just a matter of executing a command similar to the next one, replacing `<problem_id>` with the id of the desired problem:

    $ ./<problem_id>

Unless stated otherwise, every problem in this repository reads from the standard input and writes to the standard output.

## Problems Solved

The following is the list of the problems solved. Each problem id is specified between round brackets. Problems marked with ✓ are done, while problems with ✗ are not complete and/or aren't efficient enough.

### Qualification Round

* ✓ [15: Cooking the Books][qual1] (`cooking-the-books`)
* ✓ [30: New Year's Resolution][qual2] (`new-years-resolution`)
* ✓ [55: Laser Maze][qual3] (`laser-maze`)

### Round 1

* ✗ [10: Homework][round11] (`homework`)
* ✓ [25: Autocomplete][round12] (`autocomplete`)
* ✓ [25: Winning at Sports][round13] (`winning-at-sports`)
* ✓ [40: Corporate Gifting][round14] (`corporate-gifting`)

[1]: https://www.facebook.com/hackercup
[qual1]: https://www.facebook.com/hackercup/problems.php?pid=582062045257424&round=742632349177460
[qual2]: https://www.facebook.com/hackercup/problems.php?pid=1036037553088752&round=742632349177460
[qual3]: https://www.facebook.com/hackercup/problems.php?pid=1523599254559737&round=742632349177460
[round11]: https://www.facebook.com/hackercup/problems.php?pid=582396081891255&round=344496159068801
[round12]: https://www.facebook.com/hackercup/problems.php?pid=313229895540583&round=344496159068801
[round13]: https://www.facebook.com/hackercup/problems.php?pid=688426044611322&round=344496159068801
[round14]: https://www.facebook.com/hackercup/problems.php?pid=759650454070547&round=344496159068801
