
[source](https://www.interviewcake.com/cpp-interview-questions)

## What is the difference between a shallow and a deep copy of a class?
### Answer
`Shallow copying is faster, but it's "lazy" in how it handles pointers and references. Instead of making a fresh copy of the actual data the pointer points to, it just copies over the pointer value. So, both the original and the copy will have pointers that reference the same underlying data.<br> Deep copying actually clones the underlying data; it's not shared between the original and the copy.</br> In C++, there are two functions that copy the values from one object to another: copy constructors and copy assignment operators. The copy constructor gets called whenever we are constructing a new object from an existing one. So, this declaration uses copy constructors; The copy assignment operator gets called when we're updating an existing object.`


## What is a template function?
### Answer
`C++ makes us specify the types for function arguments and return values. Templates let us write functions that take in any type. This helps us keep our code DRY.<br> Ex. Using templates, we can combine all three swap functions (for type names char, int and string for eg.) like this:`

`template <typename T>
void mySwap(T& x, T& y)
{
    T tmp = x;
    x = y;
    y = tmp;
};`

**Careful**
`C++ templates can make programs "bloated" by increasing the amount of code that needs to be compiled. Remember the three different swap functions we created earlier? Behind the scenes, the C++ compiler is generating all three of those functions: one for integers, one for strings, and one for characters. Using templates saves us time and makes our code shorter, but we're definitely not saving any space.`


## What is the Diamond problem? How can we get around it?
### Answer
`The diamond problem refers to an issue when a base class is inherited by two subclasses, and both subclasses are inherited by a fourth class. When this happens, we need to give the compiler a bit of guidance about the exact structure of inheritance we want.`


## Write a function that takes a string and reverses the letters in place. 
### Solution
`We swap the first and last characters, then the second and second-to-last characters, and so on until we reach the middle.`


## Inflight entertainment
## **You've built an inflight entertainment system with on-demand movie streaming.**
`Users on longer flights like to start a second movie right when their first one ends, but they complain that the plane usually lands before they can see the ending.`
**So you're building a feature for choosing two movies whose total runtimes will equal the exact flight length.**
`Write a function that takes an integer flightLength (in minutes) and a vector of integers movieLengths (in minutes) and returns a boolean indicating whether there are two numbers in movieLengths whose sum equals flightLength.<br> When building your function:</br>`
- Assume your users will watch exactly two movies
- Don't make your users watch the same movie twice
- Optimize for runtime over memory.

### Breakdown
`How would we solve this by hand? We know our two movie lengths need to sum to flightLength. So for a given firstMovieLength, we need a secondMovieLength that equals flightLength - firstMovieLength.</br> To do this by hand we might go through movieLengths from beginning to end, treating each item as firstMovieLength, and for each of those check if there's a secondMovieLength equal to flightLength - firstMovieLength.<br> How would we implement this in code? We could nest two loops (the outer choosing firstMovieLength, the inner choosing secondMovieLength). That’d give us a runtime of O(n^2). We can do better.</br> We can do this in O(n)O(n) time, where nn is the length of movieLengths.`
<br>
`To bring our runtime down we'll probably need to replace that inner loop (the one that looks for a matching secondMovieLength) with something faster. We could sort the movieLengths first—then we could use binary search to find secondMovieLength in O(\lg{n})O(lgn) time instead of O(n)O(n) time. But sorting would cost O(nlg(n))O(nlg(n)), and we can do even better than that.<br> Could we check for the existence of our secondMovieLength in constant time?<br> What data structure gives us convenient constant-time lookups? An unordered set!<br> So we could throw all of our movieLengths into an unordered set first, in O(n)O(n) time. Then we could loop through our possible firstMovieLengths and replace our inner loop with a simple check in our unordered set. This'll give us O(n)O(n) runtime overall! Of course, we need to add some logic to make sure we're not showing users the same movie twice...<br> But first, we can tighten this up a bit. Instead of two sequential loops, can we do it all in one loop? (Done carefully, this will give us protection from showing the same movie twice as well.)`

### Solution

`We make one pass through movieLengths, treating each item as the firstMovieLength. At each iteration, we:<br>`
- See if there's a matchingSecondMovieLength we've seen already (stored in our movieLengthsSeen unordered set) that is equal to flightLength - firstMovieLength. If there is, we short-circuit and return true.
- Keep our movieLengthsSeen unordered set up to date by throwing in the current firstMovieLength.


## Permutation palindrome
## **Write an efficient function that checks whether any permutation of an input string is a palindrome**
You can assume the input string only contains lowercase letters.

### Solution
`Our approach is to check that each character appears an even number of times, allowing for only one character to appear an odd number of times (a middle character). This is enough to determine if a permutation of the input string is a palindrome. We iterate through each character in the input string, keeping track of the characters we’ve seen an odd number of times using an unordered set unpairedCharacters.<br> As we iterate through the characters in the input string:<br>`
- If the character is not in unpairedCharacters, we add it.
- If the character is already in unpairedCharacters, we remove it.
Finally, we just need to check if less than two characters don’t have a pair.


## Merging ranges
**Your company built an in-house calendar tool called HiCal. You want to add a feature to see the times in a day when everyone is available.**
`To do this, you’ll need to know when any team is having a meeting. In HiCal, a meeting is stored as an instance of a Meeting class with integer member variables startTime and endTime. These integers represent the number of 30-minute blocks past 9:00am.`

`class Meeting
{
private:
    // number of 30 min blocks past 9:00 am
    unsigned int startTime_;
    unsigned int endTime_;

public:
    Meeting() :
        startTime_(0),
        endTime_(0)
    {
    }

    Meeting(unsigned int startTime, unsigned int endTime) :
        startTime_(startTime),
        endTime_(endTime)
    {
    }

    unsigned int getStartTime() const
    {
        return startTime_;
    }

    void setStartTime(unsigned int startTime)
    {
        startTime_ = startTime;
    }

    unsigned int getEndTime() const
    {
        return endTime_;
    }

    void setEndTime(unsigned int endTime)
    {
        endTime_ = endTime;
    }

    bool operator==(const Meeting& other) const
    {
        return
            startTime_ == other.startTime_
            && endTime_ == other.endTime_;
    }
};`

For example:<br>

`Meeting meeting1(2, 3);  // meeting from 10:00 – 10:30 am
Meeting meeting2(6, 9);  // meeting from 12:00 – 1:30 pm`

***Write a function mergeRanges() that takes a vector of multiple meeting time ranges and returns a vector of condensed ranges.***<br>
For example, given:<br>
`[Meeting(0, 1), Meeting(3, 5), Meeting(4, 8), Meeting(10, 12), Meeting(9, 10)]`<br>
your function would return:<br>
`[Meeting(0, 1), Meeting(3, 8), Meeting(9, 12)]`<br>

***Do not assume the meetings are in order.*** The meeting times are coming from multiple teams.
***Write a solution that's efficient even when we can't put a nice upper bound on the numbers representing our time ranges***

### Solution
`First, we sort our input vector of meetings by start time so any meetings that might need to be merged are now next to each other. Then we walk through our sorted meetings from left to right. At each step, either:<br>`
1. We can merge the current meeting with the previous one, so we do.
2. We can't merge the current meeting with the previous one, so we know the previous meeting can't be merged with any future meetings and we throw the current meeting into mergedMeetings.



