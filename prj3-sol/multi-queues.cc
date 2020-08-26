#include <fstream>
#include <iostream>
#include <unordered_map>

#include "priority-queue.hh"

struct job
{
    std::string id;
    int priority0;
    int priority1;
};

class job_comparable : public Comparable
{
public:
	std::string id;
	int priority;

    job_comparable(std::string id, int priority)
        : id(id), priority(priority) {}

	virtual int compare(const Comparable& other) const
	{
        auto rhs = dynamic_cast<const job_comparable*>(&other);

		if (priority != rhs->priority)
            return priority - rhs->priority;

        return id.compare(rhs->id);
	}
};

void print_usage(char* call)
{
    std::cout << "usage:\n\t" << call << " FILE_PATH\n";
}

int main(int argc, char** argv)
{
    if (argc != 2)
    {
        print_usage(argv[0]);
        return 1;
    }

    std::unordered_map<std::string, job> jobs;

    priority_queue<job_comparable> queue0;
    priority_queue<job_comparable> queue1(true);

    std::fstream file(argv[1]);

    if (!file.is_open())
    {
        std::cerr << "issue opening the file " << argv[1] << std::endl;
        return 1;
    }

    std::string word;

    while (file >> word)
    {
        if (word.compare("enter") == 0)
        {
            std::string id;
            int priority0;
            int priority1;

            file >> id;
            file >> priority0;
            file >> priority1;

            jobs[id] = { id, priority0, priority1 };

            queue0.push({ id, priority0 });

            std::cout << "enter " << id << " " << priority0 << " " << priority1 << std::endl;
        }
        else if (word.compare("move") == 0)
        {
            if (!queue0.empty())
            {
                job_comparable jc = queue0.pop();

                job j = jobs[jc.id];

                queue1.push({ j.id, j.priority1 });

                std::cout << "move " << j.id << " " << j.priority0 << " " << j.priority1 << std::endl;
            }
        }
        else if (word.compare("leave") == 0)
        {
            if (!queue1.empty())
            {
                job_comparable jc = queue1.pop();

                job j = jobs[jc.id];

                std::cout << "leave " << j.id << " " << j.priority0 << " " << j.priority1 << std::endl;
            }
        }
        else
        {
            std::cerr << word << " is not a valid command. exiting" << std::endl;
            return 1;
        }
    }

    return 0;
}
