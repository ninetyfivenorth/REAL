#pragma once

#include <optional>
#include <string>
#include <vector>

namespace miniant::Windows::Filesystem {

#ifdef _UNICODE
using WindowsString = std::wstring;
#else
using WindowsString = std::string;
#endif

WindowsString WrapInDoubleQuotes(const WindowsString& string);
bool ExecuteCommand(const WindowsString& command, bool asAdministrator);

WindowsString GetExecutablePath();
WindowsString GetTempDirectory();

std::optional<std::vector<WindowsString>> GetPathComponents(const WindowsString& path);
std::optional<WindowsString> GetName(const WindowsString& path);
std::optional<WindowsString> GetParentDirectory(const WindowsString& path);

bool IsDirectory(const WindowsString& path);
bool IsFile(const WindowsString& path);

WindowsString GetDeleteCommand(const WindowsString& filepath);
WindowsString GetMoveCommand(const WindowsString& source, const WindowsString& destination);
WindowsString GetRenameCommand(const WindowsString& source, const WindowsString& newName);
WindowsString GetExtractZipCommand(const WindowsString& zipfile, const WindowsString& destination);

bool CanWriteTo(const WindowsString& path);

bool MoveFile(const WindowsString& source, const WindowsString& destination);
bool RenameFile(const WindowsString& source, const WindowsString& newName);
bool DeleteFile(const WindowsString& filepath);

bool CreateDirectory(const WindowsString& path);
bool ExtractZip(const WindowsString& zipfile, const WindowsString& destination);
}
