# Auto-Complete

The idea is to design a system that predicts the word the user is going to type before he/she completes it. 
This can be done by allowing him/her to choose from a list of words as they type letter by letter. 
The DATA STRUCTURES employed are LINK-LIST, STACK, and GRAPH. 
The letters in the keyboard are connected in graph with keys as the vertices. 
Depth-first search is used to find the closest letters in the graph. 
The adjacent letters are looked upon for the possibility of meaningful words and are listed. 
This is done by comparing the words with a data-set that is downloaded already from internet. 
Each time a new letter is entered the choice list is refreshed. 
The user can also edit the words in the sentence as he/she finishes it. 
Some high priority words are replaced automatically when the user types it ie., typo corrections. 
> For eg: when the word ‘the’ is typed as ‘thw’, it is automatically replaced with ‘the’. As the letter ‘w’ is the adjacent of ‘e’, it is replaced automatically with ‘the’ since it is the most probable word. 

STACK is employed for recording the order of editing the words. 
