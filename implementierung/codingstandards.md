CVVisual Coding-Guidelines
==========================

In general the OpenCV-guidlines are to be followed, unless noted otherwise below.
Also: Use common sense; following a rule blindly is as stupid as following no rules at all.


Naming
------

* Classes and Classtemplates are named using PascalCase
* Methods, Functions and Functiontemplates are named using camelCase
* Variables use camelCase
* Template-Arguments use PascalCase
* getters are often better named without ‘get’: foo.data() instead of foo.getData()
* If there are setters (which is often a sign of bad design) the getters should however be named getFoo()

Technical
---------

* Only ever indent with tabs!! Make sure your IDE does that too!
* indent empty lines
* other than the above rule: No trailing whitespace
* opening braces belong on their own line, because this is what opencv does (they are wrong!)
* If you display tabs as eight spaces, your lines should not be longer than 100 characters

Code
----

* Try hard to avoid more than one raw loop per function (std::for\_each is a raw loop). Use algorithms instead
* In general: avoid functions that are overly complex
* But make your function do SOMETHING, if isn't meant to be a trivial one. Ten function with one line i
	each are more difficult to comprehend then one function with ten lines.
* If something is a function, don't make it a class
* Use lambdas where appropriate. No more nor less.
* Trust the compiler: Don't optimize prematurely
* The opposite is also true: No premature pessimisation
* Don't use unchecked container-access: instead of foo[3] use foo.at(3)
* NEVER use blank arrays, always use std::vector or std::array
* Don't return lambdas from functions, unless you really know what you are doing
* Don't mix signed and unsigned integers. If in doubt: use size\_t
* Your Include-guards should all have the form of CVVISUAL\_FILE\_NAME\_HPP (opencv's naming convention
	results in undefined behaviour)
