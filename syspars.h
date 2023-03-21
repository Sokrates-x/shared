#ifndef PARAMETER_STRUCTS_H
#define PARAMETER_STRUCTS_H 1

//===================================Machine Setup Params============================================//
struct ContactSearchMethod {
	double search_sensor_tolerance;
	int auto_contact_search_adjust;
	double auto_contact_search_height;
	double release_distance;
	double release_speed;
	double initialization_force;
	double operation_contact_search_speed;
	double contact_force;
};

struct MajorClamp {
	double stage1_major_clamp_open_force;
	double stage2_major_clamp_open_force;
	double stage3_major_clamp_open_force;
	double stage1_major_clamp_close_force;
	double stage2_major_clamp_close_force;
	double stage3_major_clamp_close_force;
	double stage1_major_clamp_manual_close_force;
	double stage2_major_clamp_manual_close_force;
	double stage3_major_clamp_manual_close_force;
	double stage1_major_clamp_loop_close_force;
	double stage2_major_clamp_loop_close_force;
	double stage3_major_clamp_loop_close_force;
	double stage1_clamp_open_ramp_time;
	double stage2_clamp_open_ramp_time;
	double stage3_clamp_open_ramp_time;
	double stage1_clamp_close_ramp_time;
	double stage2_clamp_close_ramp_time;
	double stage3_clamp_close_ramp_time;
};

struct ClampMethod {
	double clamp_action_delay_time;
	int first_bond_clamp_state;
	int second_bond_clamp_state;
};

struct WireClamp {
	struct MajorClamp major_clamp;
	struct ClampMethod clamp_method;
};

struct BondMode {
	int step_by_step_bond_mode;
	int step_by_step_bond_mode_setup;
	int dry_run_mode;	
	int dry_run_mode_setup;
};

struct RunPosition {
	double reset_height;
};

struct BondControlSetup {
	struct ContactSearchMethod contact_search_method;
	struct WireClamp wire_clamp;
	struct BondMode bond_mode;
	struct RunPosition run_position;
};

struct RunSpeed {
	double bonding_speed;
	double pr_speed;
	double slow_move_speed;
};

struct MachineSetupParams {
	int bond_head_type;
	struct BondControlSetup bond_control_setup;
	struct RunSpeed run_speed;
};

//======================================Bonding Params===============================================//
struct ContactSearch {
    double search_history_result;
    double search_height;
    double search_lower_limit;
    double search_velocity;
    double search_force;
	double standby_power;
};

struct BondingMode {
    double trigger_distance;
    double delay;
};

struct BondingStage {	
	int stage_switch;
	double stage_ultrasonic;
	double stage_bond_force;
	double stage_time;
	double stage_us_ramp;
	double stage_force_ramp;
	int stage_us_ramp_mode;
	int stage_force_ramp_mode;
};

struct Bonding {
    int deformation_bond_mode_switch;
    double min_bond_time;
    double deformation_threshold;
	double min_ultrasonic;
	struct BondingStage bonding_stages[12];
};

struct TearOff {
    double tail_length;
    double tear_off_distance;
    double tear_force;
    double tear_utrasonic;
    double safety_distance;
    double tear_off_angle;
    double tail_utrasonic;
    double cutter_distance_z;
	double cutter_distance;
	double tear_off_velocity;
	double cut_depth;
	double cut_force;
	double cut_velocity;
	double hop_height;
	double hop_velocity;
};

struct LoopProfile {
    double loop_height;
	double twist_height;
	double step_forward_angle;
	double descent_delay;
};

struct QualityCheck {
    int deformation_check_mode;
    double deformation_up_limit;
    double deformation_down_limit;
};

struct BondParams {
	// Wire Params
	double wire_angle;
	double starting_height;
	double first_point_x;
	double first_point_y;
	double second_point_x;
	double second_point_y;
	//- First Bond
		// Switch	
		int first_bond_enable;
		// Contact Search
		struct ContactSearch first_contact_search;
		struct BondingMode first_bonding_mode;
		struct Bonding first_bonding;
		struct QualityCheck first_quality_check;
	
	//- Looping	
		// Switch
		int loop_process_enable;
		// Loop Params
		struct LoopProfile loop_profile;

	//- Second Bond
		// Switch
		int second_bond_enable;
		// Contact Serach
		struct ContactSearch second_contact_search;
		struct BondingMode second_bonding_mode;
		struct Bonding second_bonding;
		struct QualityCheck second_quality_check;
	
	//- TearOff
		// Switch
		int tearoff_enable;
		// Tearoff Params
		struct TearOff tear_off;

	// Ready for Bonding
	int bp_valid;
};

//====================================Reset Move Params==============================================//

struct ResetMoveParams {
	double x_position;
	double y_position;
	double z_position;
	double p_position;
	double vel_acc_factor;
};

//====================================System Move Params==============================================//

struct SystemMoveParams {
	double x_position;
	double y_position;
	double z_position;
	double p_position;
	double vel_acc_factor;
};

//==================================Contact Search Params=============================================//

struct ContactSearchParams {
	double first_x_position;
	double first_y_position;
	double first_p_position;
	double second_x_position;
	double second_y_position;
	double second_p_position;
	double focus_height;
	int contact_point_select;
	double vel_acc_factor;
};

#endif
