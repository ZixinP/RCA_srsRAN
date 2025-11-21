
namespace srsran {
namespace mac {

//... other structs like pf_sched_args_t

// Configuration arguments for the new Greedy scheduler.
struct greedy_sched_args_t {};

// Main scheduler policy configuration struct
struct policy_sched_cfg_t {
  //... existing members like pf_sched
  std::optional<pf_sched_args_t> pf_sched;
  
  // Add our new scheduler's optional configuration
  std::optional<greedy_sched_args_t> greedy_sched;
};

//... rest of the file
