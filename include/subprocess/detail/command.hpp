#pragma once

#include <filesystem>
#include <initializer_list>
#include <memory>
#include <new>
#include <string>
#include <subprocess/detail/file_descriptor.hpp>
#include <subprocess/subprocess_export.h>

namespace subprocess
{

/**
 * @brief Main interface class for subprocess library
 *
 * A class that contains a list of linked shell commands and is responsible
 * for managing their file descriptors such that their input and output can
 * be chained to other commands.
 *
 */
class SUBPROCESS_EXPORT command
{
public:
  command(std::initializer_list<const char*> cmd);

  command(const command& other) = delete;
  command(command&& other);
  command& operator=(const command& other) = delete;
  command& operator                        =(command&& other);

  ~command();

  int run();

  int run(std::nothrow_t);

  command& operator|(command&& other);

private:
  struct SUBPROCESS_NO_EXPORT PrivateImpl;
  std::unique_ptr<PrivateImpl> pimpl;

  friend command& operator<(command& cmd, file_descriptor fd);
  friend command&& operator<(command&& cmd, file_descriptor fd);
  friend command& operator<(command& cmd, std::string& input);
  friend command&& operator<(command&& cmd, std::string& input);
  friend command& operator<(command& cmd, std::filesystem::path file_name);
  friend command&& operator<(command&& cmd, std::filesystem::path file_name);

  friend command& operator>(command& cmd, file_descriptor fd);
  friend command&& operator>(command&& cmd, file_descriptor fd);
  friend command& operator>(command& cmd, std::string& output);
  friend command&& operator>(command&& cmd, std::string& output);
  friend command& operator>(command& cmd, const std::filesystem::path& file_name);
  friend command&& operator>(command&& cmd, const std::filesystem::path& file_name);

  friend command& operator>=(command& cmd, file_descriptor fd);
  friend command&& operator>=(command&& cmd, file_descriptor fd);
  friend command& operator>=(command& cmd, std::string& output);
  friend command&& operator>=(command&& cmd, std::string& output);
  friend command& operator>=(command& cmd, const std::filesystem::path& file_name);
  friend command&& operator>=(command&& cmd, const std::filesystem::path& file_name);

  friend command& operator>>(command& cmd, file_descriptor fd);
  friend command&& operator>>(command&& cmd, file_descriptor fd);
  friend command& operator>>(command& cmd, const std::filesystem::path& file_name);
  friend command&& operator>>(command&& cmd, const std::filesystem::path& file_name);

  friend command& operator>>=(command& cmd, file_descriptor fd);
  friend command&& operator>>=(command&& cmd, file_descriptor fd);
  friend command& operator>>=(command& cmd, const std::filesystem::path& file_name);
  friend command&& operator>>=(command&& cmd, const std::filesystem::path& file_name);
};

SUBPROCESS_EXPORT command& operator<(command& cmd, file_descriptor fd);
SUBPROCESS_EXPORT command&& operator<(command&& cmd, file_descriptor fd);
SUBPROCESS_EXPORT command& operator<(command& cmd, std::string& input);
SUBPROCESS_EXPORT command&& operator<(command&& cmd, std::string& input);
SUBPROCESS_EXPORT command& operator<(command& cmd, std::filesystem::path file_name);
SUBPROCESS_EXPORT command&& operator<(command&& cmd, std::filesystem::path file_name);

SUBPROCESS_EXPORT command& operator>(command& cmd, file_descriptor fd);
SUBPROCESS_EXPORT command&& operator>(command&& cmd, file_descriptor fd);
SUBPROCESS_EXPORT command& operator>(command& cmd, std::string& output);
SUBPROCESS_EXPORT command&& operator>(command&& cmd, std::string& output);
SUBPROCESS_EXPORT command& operator>(command& cmd, const std::filesystem::path& file_name);
SUBPROCESS_EXPORT command&& operator>(command&& cmd, const std::filesystem::path& file_name);

SUBPROCESS_EXPORT command& operator>=(command& cmd, file_descriptor fd);
SUBPROCESS_EXPORT command&& operator>=(command&& cmd, file_descriptor fd);
SUBPROCESS_EXPORT command& operator>=(command& cmd, std::string& output);
SUBPROCESS_EXPORT command&& operator>=(command&& cmd, std::string& output);
SUBPROCESS_EXPORT command& operator>=(command& cmd, const std::filesystem::path& file_name);
SUBPROCESS_EXPORT command&& operator>=(command&& cmd, const std::filesystem::path& file_name);

SUBPROCESS_EXPORT command& operator>>(command& cmd, file_descriptor fd);
SUBPROCESS_EXPORT command&& operator>>(command&& cmd, file_descriptor fd);
SUBPROCESS_EXPORT command& operator>>(command& cmd, const std::filesystem::path& file_name);
SUBPROCESS_EXPORT command&& operator>>(command&& cmd, const std::filesystem::path& file_name);

SUBPROCESS_EXPORT command& operator>>=(command& cmd, file_descriptor fd);
SUBPROCESS_EXPORT command&& operator>>=(command&& cmd, file_descriptor fd);
SUBPROCESS_EXPORT command& operator>>=(command& cmd, const std::filesystem::path& file_name);
SUBPROCESS_EXPORT command&& operator>>=(command&& cmd, const std::filesystem::path& file_name);

} // namespace subprocess