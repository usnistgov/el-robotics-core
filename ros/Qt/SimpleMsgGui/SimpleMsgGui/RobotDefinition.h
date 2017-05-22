#ifndef ROBOTDEFINITION_H
#define ROBOTDEFINITION_H


struct RobotDef
{
    std::string name;
    std::vector<std::string> jointnames;
    std::map<std::string, double  > jointposvalues;  // these are raw values not sorted by robot
    std::vector<float>  jointmaxvalues;  // in order of jointnames
    std::vector<float>  jointminvalues;  // in order of jointnames

    QString ip;
    int cmdport;
    int statusport;
    int byteswap;
    std::vector<std::string> versions;
    std::string version;
    std::vector<std::string> controllers;
    std::string controller;

    int pubvel;
    int pubeffort;
    int pubpos;
    std::string eelink, world;
    size_t maxjoints()
    {
        return jointnames.size();
#if 0
        size_t jnmax =0;
        std::map<std::string, std::vector<std::string> >::iterator it = jointnames.begin();
        for(; it!= jointnames.end(); it++)
        {
            if((*it).second.size() > jnmax)
                jnmax=(*it).second.size();
        }
        return jnmax;
#endif
    }

};

#endif // ROBOTDEFINITION_H
