#include <iostream>
#include <sys/wait.h>
#include <unistd.h>

int main() {
  std::cout << "ccsh> ";
  std::string command;
  std::getline(std::cin, command);
  std::string exec_path = "/bin/" + command;

  pid_t pid = fork();

  if (pid == -1) {
    // Error handling for fork failure
    std::cerr << "Fork failed!" << std::endl;
    return 1;
  } else if (pid == 0) {
    // Replace with the path and arguments of the desired executable
    char *argv[] = {const_cast<char *>(exec_path.c_str()), nullptr};

    execvp(argv[0], argv);

    // execvp returns only if an error occurs
    perror("execvp");
    exit(EXIT_FAILURE);
  } else {
    // Parent process
    // std::cout << "Parent process ID: " << getpid() << std::endl;

    // Optionally, wait for the child process to complete
    int status;
    waitpid(pid, &status, 0);
    // std::cout << "Child process exited with status " << status << std::endl;
  }

  return 0;
}
