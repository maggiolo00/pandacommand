using Gee;
public interface PandaPlugin : GLib.Object {


  public abstract void init();
  public signal void  register(string cmd,Gee.List<string>? arg);
  public signal void  register_rpc(string json);
  public signal void unregister(string cmd);
  public abstract string invoke(string cmd,Gee.List<string> arg);
  public abstract string invoke_rpc(string json);
  public abstract string get_handler_path();
  public abstract string get_dashboard_html(string context);
}

