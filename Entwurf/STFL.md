#STFL - Simple Table Filter Language
A simple language to filter, group and sort items in a table. It's inspired by the search query language of esotalk.

##Language Specification

A query consist of some free text (the '#''s have to be masked as '\#''s) followed by optional filter statements.
The statements start with a '#' and end with the beginning of the next statement or the end of the query.
The query overall consists only of one line of text.
The following sections describe the different types of STFL statements.



###Filter statement
A filter statement has the following structure:
	
	#[descriptor]:[free text]

A descriptor is a single word consisting of alpha numerical characters and underscores, can't be empty and are case insensitive.
Whitespace between the collon and the free text is ommitted.
Example usage:
Say, you only want to see data items that are captured in line 200, then append ´#line:200´ to your query.

###Group statement
A group statement allows the grouping of the items and has the following structure:
	
	#group by [descriptor]
	//or with several grouping criterias (short cut for chaining)
	#group by [descriptor one] and [...] and [descriptor n]

Example usage:
Say, you want to group the data items by there line number (and implicitely by their file name), then append ´#group by line´ to your query.

###Sort statement
A sort statement allows the sorting of the items according to a rule (´[descriptor]´). It has the following structure

	#sort by [descriptor]
	//or with several sorting criterias (short cut for chaining)
	#group by [descriptor one] and [...] and [descriptor n]

If chained, the succeeding sorting statements will only sort the equal sorting groups of the prior statements.
Example usage:
Say, you want to sort the data items according to the file and line number, then append ´#group by file and line´ to your query.

###Custom statement
A custom statement is implementation specific and therefore covered in another section.
