#include "Program.h"
antlrcpp::Any *Program::getValue(std::string name)
{
    while(!frames.empty()) {
        if (frames.top().memory->count(name)){
            Any *ret = &((*(frames.top().memory))[name]);
            while(!tmp_frames.empty())
                frames.push(tmp_frames.pop());
            //incorrect, since variables in a() should not be used in b() during a(b(x))
            return ret;
        }
        else tmp_frames.push(frames.pop());
    }
    while(!tmp_frames.empty())
        frames.push(tmp_frames.pop());
    return nullptr;
}