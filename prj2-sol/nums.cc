#include <fstream>
#include <iostream>
#include <string>

#include "arrayseq.hh"
#include "dlinkseq.hh"
#include "seq.hh"

using TestType = int;

bool read_input_file(std::string path, Seq<TestType>* seq)
{
    std::ifstream in_file(path);

    if (!in_file)
    {
        std::cerr << "cannot read " << path << ": No such file or directory\n";

        return false;
    }

    std::string w;

    while (in_file >> w)
    {
        seq->push(std::stoi(w));
    }

    if (!in_file.eof())
    {
        std::cerr << "encountered an error while reading " << path << '\n';

        return false;
    }

    return true;
}

void output_seq(Seq<TestType>* seq)
{
    const auto front_itp = seq->cbegin();
    const auto back_itp = seq->cend();

    auto& front_it = *front_itp;
    auto& back_it = *back_itp;

    while (front_it && back_it)
    {
        std::cout << *front_it << '\n' << *back_it << '\n';

        ++front_it;
        --back_it;
    }
}

int main(int argc, char** argv)
{
    if (argc < 2 || argc > 3 || (argc == 3 && std::string(argv[1]) != "-a"))
    {
        std::cerr << "usage:\n\t./nums [-a] INTS_FILE_PATH\n";

        return 1;
    }
    
    SeqPtr<TestType> seq = DLinkSeq<TestType>::make();
    
    if (argc == 3)
        seq = ArraySeq<TestType>::make();

    if (!read_input_file(argv[argc - 1], seq.get()))
        return 1;

    output_seq(seq.get());

    return 0;
}
