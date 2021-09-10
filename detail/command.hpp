#include <string>
#include <initializer_list>
#include <filesystem>
#include <memory>
#include "file_descriptor.hpp"

namespace subprocess
{

    class command
    {
    public:
        command(std::initializer_list<const char *> cmd);

        command(const command &other);
        command(command &&other);
        command &operator=(const command &other);
        command &operator=(command &&other);

        ~command();

        int run();

        command &operator|(command&& other);

    private:
        struct PrivateImpl;
        std::unique_ptr<PrivateImpl> pimpl;

        friend command &operator<(command &cmd, file_descriptor fd);
        friend command &&operator<(command &&cmd, file_descriptor fd);
        friend command &operator<(command &cmd, std::string &input);
        friend command &&operator<(command &&cmd, std::string &input);
        friend command &operator<(command &cmd, std::filesystem::path file_name);
        friend command &&operator<(command &&cmd, std::filesystem::path file_name);

        friend command &operator>(command &cmd, file_descriptor fd);
        friend command &&operator>(command &&cmd, file_descriptor fd);
        friend command &operator>(command &cmd, std::string &output);
        friend command &&operator>(command &&cmd, std::string &output);
        friend command &operator>(command &cmd, const std::filesystem::path &file_name);
        friend command &&operator>(command &&cmd, const std::filesystem::path &file_name);

        friend command &operator>=(command &cmd, file_descriptor fd);
        friend command &&operator>=(command &&cmd, file_descriptor fd);
        friend command &operator>=(command &cmd, std::string &output);
        friend command &&operator>=(command &&cmd, std::string &output);
        friend command &operator>=(command &cmd, const std::filesystem::path &file_name);
        friend command &&operator>=(command &&cmd, const std::filesystem::path &file_name);

        friend command &operator>>(command &cmd, file_descriptor fd);
        friend command &&operator>>(command &&cmd, file_descriptor fd);
        friend command &operator>>(command &cmd, const std::filesystem::path &file_name);
        friend command &&operator>>(command &&cmd, const std::filesystem::path &file_name);

        friend command &operator>>=(command &cmd, file_descriptor fd);
        friend command &&operator>>=(command &&cmd, file_descriptor fd);
        friend command &operator>>=(command &cmd, const std::filesystem::path &file_name);
        friend command &&operator>>=(command &&cmd, const std::filesystem::path &file_name);
    };

    command &operator<(command &cmd, file_descriptor fd);
    command &&operator<(command &&cmd, file_descriptor fd);
    command &operator<(command &cmd, std::string &input);
    command &&operator<(command &&cmd, std::string &input);
    command &operator<(command &cmd, std::filesystem::path file_name);
    command &&operator<(command &&cmd, std::filesystem::path file_name);

    command &operator>(command &cmd, file_descriptor fd);
    command &&operator>(command &&cmd, file_descriptor fd);
    command &operator>(command &cmd, std::string &output);
    command &&operator>(command &&cmd, std::string &output);
    command &operator>(command &cmd, const std::filesystem::path &file_name);
    command &&operator>(command &&cmd, const std::filesystem::path &file_name);

    command &operator>=(command &cmd, file_descriptor fd);
    command &&operator>=(command &&cmd, file_descriptor fd);
    command &operator>=(command &cmd, std::string &output);
    command &&operator>=(command &&cmd, std::string &output);
    command &operator>=(command &cmd, const std::filesystem::path &file_name);
    command &&operator>=(command &&cmd, const std::filesystem::path &file_name);

    command &operator>>(command &cmd, file_descriptor fd);
    command &&operator>>(command &&cmd, file_descriptor fd);
    command &operator>>(command &cmd, const std::filesystem::path &file_name);
    command &&operator>>(command &&cmd, const std::filesystem::path &file_name);

    command &operator>>=(command &cmd, file_descriptor fd);
    command &&operator>>=(command &&cmd, file_descriptor fd);
    command &operator>>=(command &cmd, const std::filesystem::path &file_name);
    command &&operator>>=(command &&cmd, const std::filesystem::path &file_name);

}