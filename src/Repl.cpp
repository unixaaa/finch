#include <iostream>
#include <string>

#include "String.h"
#include "Repl.h"

namespace Finch
{
    void Repl::Run()
    {
        bool   running = true;
        String line;
        
        std::cout << "finch 0.0.0d\n";
        
        while (running)
        {
            std::cout << "> ";
            getline(std::cin, line);
            
            if (line == "quit")
            {
                running = false;
            }
            else
            {
                auto_ptr<Expr> expr = mParser.ParseLine(line.c_str());
                if (expr.get() != NULL)
                {
                    std::cout << "expr: ";
                    expr->Trace(std::cout);
                    std::cout << std::endl;
                }
                else
                {
                    std::cout << "Parse error" << std::endl;
                }
            }
        }
    }
}