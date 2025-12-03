#include <fstream>
#include <iostream>
#include <string>
#include <vector>

// ============================================================================
// INSTRUCTIONS
// ============================================================================
// 1. Implement the three functions below.
// 2. You may use the main() function at the bottom to test your code locally.
// 3. Do not change the function signatures.
// ============================================================================

// TODO: Implement this function to return a vector of strings
// containing the names of everyone on your team.
std::vector<std::string> GetTeamMembers() {
  return {"Andrew Arteaga", "Michael LeBlanc"};
}

// TODO: Implement this function to return a string that describes
// the strategy your logic uses to bid (e.g., "We bid high early on").
std::string GetStrategy() {
  return "We start conservative and slowly increase";
}

void GenerateBids(int rounds, int budget, std::string output_filename) {
  std::ofstream outfile(output_filename);
  if (!outfile.is_open()) {
    std::cerr << "Error: Could not open file " << output_filename << std::endl;
    return;
  }

  int base_bid = budget / rounds;
  int remainder = budget % rounds;

  for (int i = 0; i < rounds; ++i) {
    int bid = base_bid;
    if (i < remainder) {
      bid += 1;  
    }
    outfile << bid << "\n";
  }

  outfile.close();
}

// ============================================================================
// MAIN FUNCTION
// ============================================================================
int main() {
  // Example test
  GenerateBids(10, 100, "test_output.txt");

  std::cout << "Team Members:\n";
  for (const auto& member : GetTeamMembers()) {
    std::cout << "- " << member << "\n";
  }

  std::cout << "Strategy: " << GetStrategy() << std::endl;

  return 0;
}
