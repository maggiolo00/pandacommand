using Gee;
using Soup;
public class PandaConsole : PandaPlugin , GLib.Object {

	protected string SERVICE = "/pandaconsole";
	public signal void word_ok();	
	
	public void init() {
		Gee.List<string> args = new Gee.ArrayList<string>();
		args.add("String to play");
		register("parse",args);
	}
	public string get_dashboard_html(string context){
		string content ="";
		try {
			FileUtils.get_contents(context + "/data/index.html", out content);	
		}catch (Error err){
			warning("Error: %s\n", err.message);
		}
		return content;
	}
    public string get_handler_path(){
        return SERVICE;
    }
    public string invoke(string cmd,Gee.List<string> args){
    	if(cmd=="parse"){    		
			parse(args[0]);
    		return "command ok";
    	}
    	return "command bad";
    }
    public void parse(string command){
    	
    	if(command!=null){  p
			string[] args = command.split(" ");
		}
    }

}
public Type register_plugin (Module module) {
    return typeof (PandaConsole);
}


