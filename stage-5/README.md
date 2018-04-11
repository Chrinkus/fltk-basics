# I Can GUI
### Stage 5
---
When planning this project I knew that the content of this stage, adding widgets, would be the point at which I'd have to really get to work. The problems I had, coming out of chapter 16 in the text were:
1. There was a log of "magic" in the text due to us not learning about pointers before using FLTK
2. The Callback function signature was baffling
3. There seemed to be some extra stuff going on behind the scenes somehow..
4. There were `new`'s but no `delete`'s

```c++
template<typename W> W* down_cast(const std::unique_ptr<Fl_Widget>& pw)
{
    return static_cast<W*>(pw.get());
}
```

Also, these two lines mean the same thing but good luck trying to understand them as a newbie:
```c++
using Callback = void(*)(Fl_Widget*, void*);
typedef void(*Callback)(Address, Address);
```
They're aliases for function pointers. Declaring either at the top of the file means you don't have to type it all out when you want to declare one, just type `Callback`.
```c++
using Callback = void    (*)   (Fl_Widget*, void*);
//    name       return  ptr   parameters

typedef void    (*  Callback)  (Address, Address);
//      return  ptr name       parameters

// In both cases, the parenthesis around the asterix's prevent them from being
// applied to the return type (void vs void*)
```
As for which to use, since they do the same thing, `typedef` is the old C++98 way and `using` is the new C++11 method. I'd be interested to know why they'd change that since the new way is not much clearer than the old way, certainly not enough to risk complicating things..
