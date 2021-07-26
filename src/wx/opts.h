#ifndef WX_OPTS_H
#define WX_OPTS_H

#define NUM_KEYS 21
extern const wxChar* const joynames[NUM_KEYS];
extern wxJoyKeyBinding defkeys[NUM_KEYS * 2]; // keyboard + joystick defaults

extern struct opts_t
{
	opts_t();
	// while I would normally put large objects in front to reduce gaps,
	// I instead organized this by opts.cpp table order

	/// Display
	bool bilinear;
	int filter;
	wxString filter_plugin;
	int ifb;
	wxVideoMode fs_mode;
	int max_threads;
	int render_method;
	int video_scale;
	bool retain_aspect;
	bool keep_on_top;

	/// GB
	wxString gb_bios;
	wxString gbc_bios;
	// u16 systemGbPalette[8*3];
	bool print_auto_page, print_screen_cap;
	wxString gb_rom_dir;
	wxString gbc_rom_dir;

	/// GBA
	wxString gba_bios;
	int gba_link_type;
	wxString link_host;
	int link_proto;
	bool link_auto;
	wxString gba_rom_dir;

	/// General
	bool autoload_state, autoload_cheats;
	wxString battery_dir;
	int onlineupdates;
	long last_update;
	wxString last_updated_filename;
	bool recent_freeze;
	wxString recording_dir;
	int rewind_interval;
	wxString scrshot_dir;
	wxString state_dir;
	int statusbar;

	/// Joypad
	wxJoyKeyBinding_v joykey_bindings[4][NUM_KEYS];
	int autofire_rate;
	int default_stick;

	/// Keyboard
	wxAcceleratorEntry_v accels;

	/// Sound
	int audio_api;
	int audio_buffers;
	wxString audio_dev;
	int sound_en; // soundSetEnable()
	int gba_sound_filter;
	bool soundInterpolation;
	bool gb_declick;
	int gb_echo;
	bool gb_effects_config_enabled;
	bool dsound_hw_accel;
	int gb_stereo;
	bool gb_effects_config_surround;
	int sound_qual; // soundSetSampleRate() / gbSoundSetSampleRate()
	int sound_vol; // soundSetVolume()
	bool upmix; // xa2 only

	/// Recent
	wxFileHistory* recent;

	/// wxWindows
	// wxWidgets-generated options (opaque)
} gopts;

extern struct opt_desc
{
	const wxChar* opt;
	const char* cmd;
	const wxChar* desc;
	wxString* stropt;
	int* intopt;
	const wxChar* enumvals;
	int min, max;
	bool* boolopt;
	// current configured value
	wxString curstr;
	int curint;
#define curbool curint
} opts[];
extern const int num_opts;

extern const wxAcceleratorEntry default_accels[];
extern const int num_def_accels;

// call to load config (once)
// will write defaults for options not present and delete bad opts
// will also initialize opts[] array translations
void load_opts();
// call whenever opt vars change
// will detect changes and write config if necessary
void update_opts();
// returns true if option name correct; prints error if val invalid
bool opt_set(const wxChar* name, const wxChar* val);

#endif /* WX_OPTS_H */
