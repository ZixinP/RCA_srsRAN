#include "scheduler_time_pf.h"
#include "scheduler_time_rr.h"
#include "scheduler_time_greedy.h" // <-- ADD THIS INCLUDE

namespace srsran {
namespace mac {

//...

std::unique_ptr<scheduler_policy> scheduler_policy_factory::create(const policy_sched_cfg_t& cfg)
{
  if (cfg.pf_sched) {
    SRSRAN_LOG_INFO(logger, "Creating Proportional Fair scheduler policy.");
    return std::make_unique<scheduler_time_pf>(*cfg.pf_sched, logger);
  }

  // ADD THIS NEW BLOCK for the Greedy scheduler
  if (cfg.greedy_sched) {
    SRSRAN_LOG_INFO(logger, "Creating Greedy scheduler policy.");
    return std::make_unique<scheduler_time_greedy>(*cfg.greedy_sched, logger);
  }

  // Default to Round Robin scheduler
  SRSRAN_LOG_INFO(logger, "Creating Round Robin scheduler policy.");
  return std::make_unique<scheduler_time_rr>(logger);
}

//... rest of the file
