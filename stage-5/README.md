# Stage 5
### Adding Widgets
When planning this project I knew that the content of this stage, adding widgets, would be the point at which I'd have to really get to work. The problems I had, coming out of chapter 16 in the text were:
1. There was a log of "magic" in the text due to us not learning about pointers before using FLTK
2. The Callback function signature was baffling
3. There seemed to be some extra stuff going on behind the scenes somehow..
4. There were `new`'s but no `delete`'s
I'll try to address each of these issues as I understand them now.

## Callback Confusion
Looking back, it seems most of my frustration came down to not truly understanding what was going on with the callbacks and in particular, this section:
```c++
// Stroustrup GUI.h
typedef void* Address;    // Address is a synonym for void*
typedef void(*Callback)(Address, Address);    // FLTK's required function type for all callbacks
```
I understood that 'Address' was being used as an alias for a `void*`. I didn't know what a `void*` was but I figured that was ok for now, and the alias was being used to help me _kind of_ understand.
The next line was pure insanity. I assumed it was another alias but what was the alias and what was it for? The comment mentions a function which made sense since that's what a callback was, but... this didn't really look like a function.
Turns out it was a pointer to a function:
```c++
typedef void        (*  Callback)  (Address, Address);
//      return-type ptr name       parameters
```
Which is what we needed to pass down to the system, an address to a function to call when our widget was interacted with.

Incidently, `typedef`s are old news, apparently the new way of declaring alias's are `using` declarations:
```c++
using Callback = void         (*)   (Fl_Widget*, void*);
//    name       return-type  ptr   parameters
```
While aliasing `void*`s was meant to help us understand that it was just an Address, the Callback definition is meant to simplify the code later on so we don't need to type out the whole signature everytime we wanted to pass one. I'd be interested to know why they'd change from `typedef` to `using` since the new way is not much clearer than the old way, certainly not enough to risk complicating things..

WIP..
```c++
template<typename W> W* down_cast(const std::unique_ptr<Fl_Widget>& pw)
{
    return static_cast<W*>(pw.get());
}
```
