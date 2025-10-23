# CS210ProgrammingLanguages

**Project Summary: What problem did this solve?**
  The program was designed for a fabricated grocery store, The Corner Grocer, that needed to track how often each item is sold throughout the day. It reads a text file named ProduceList.txt, which contains a list of purchased items. The program displays a menu, allowing the user to output the frequency of purchased items in three ways:
    1. The frquency of user-specified item.
    2. A list of all purchased items and each items' purchase counts.
    3. A list of all purchased items displayed as a histogram with asterisks.
  A backup data file is created, named frequency.dat, containing all item counts. This helps the business optimize their invenetory management based on sales data.
  
**What did you do particularly well?**
  I followed best practices for maintaining readable and efficient code. I followed naming conventions, added comments for clarification and purpose, and created small modular functions to improve code clarity.
  I created two custom classes to separate objects and improve modularity of the code.
    * The ItemTracker class handles files and frequency data.
    * The Menu class receives input from the user and input validation.
  I used std::map to track item frequencies by forming key-value pairs. This allowed for faster and cleaner iterations through code.
  I created a friendly-user experience with a distinct visual menu as well as input validation that gives clear instruction the user.
  
**Where could you enhance your code? How would these improvements make your code more efficient, secure, and so on?**
  I could improve on utilizing pointers to manage memory allocation and discard unused or no longer needed code. This would improve the performance and efficiency of the program as well as prevent any memory leaks from occurring.
  Currently, the program doesn't check for misspellings or casing variations. Normalizing user input to the desired format will improve accuracy.
  Including user log info and password encryption can help improve security breaches.
  
**Which pieces of the code did you find most challenging to write, and how did you overcome this? What tools or resources are you adding to your support network?**
  The most challenging portion of the code to write was using map insertions and using pointers/refrences correctly. To overcome this gap in knowledge, I refered to the zyBooks examples and C++ STL: documentation to implement std::map behavior. The emplace() and count() methods were used to initially pair an item to a starting frequency, then check if the pair existed. The pass by reference and return by reference allowed for direct access and modification of variables and objects without the duplication of data.
  
**What skills from this project will be particularly transferable to other projects or course work?**
  * I gained experience in reading/writing files and handling file errors.
  * I designed my code around OOP principles, using encasulation effectively and dividing logic between classes.
  * I gained knowledge in STL Map, creating key-value pairs for fast data retrieval of lists.

**How did you make this program maintainable, readable, and adaptable?**
  I used the company's desired naming conventions and formatting. Each variable, class, and function was named clearly based on their purpose.
  I created the program with modularity in mind. The menus is scalable with new options that can be easily added. 
  The code is supported with descriptive in-line comments that explain the purporse of each function and any logic that is not obvious.
  The code is divided into smaller, logical file structures, which provides ease of navigation and distinct purpose for each file.
