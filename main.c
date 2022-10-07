#include <gtk/gtk.h>

// Funtion execute for signal the widgets generate. Arg need
static void print_hello (GtkWidget *widget, gpointer   data){
  int num = 10;
  int num2 = 11;
  g_print ("Hello World %d\n", num + num2);
}

static void activate (GtkApplication *app, gpointer user_data) {
  GtkWidget *fixed;
  GtkWidget *window;
  GtkWidget *button;
  GtkWidget *button_box;
  GtkWidget *label;

  // Create container fixed
  fixed = gtk_fixed_new();

  // Set properties for winow 
  window = gtk_application_window_new (app);
  gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
  gtk_window_set_title (GTK_WINDOW (window), "Window");
  gtk_window_set_default_size (GTK_WINDOW (window), 800, 600);
  gtk_window_set_resizable(GTK_WINDOW(window), FALSE);

  // Set properties for button and button-box
  button_box = gtk_button_box_new (GTK_ORIENTATION_HORIZONTAL);

  // Add button_box to fixed en position absolute
  gtk_fixed_put(GTK_FIXED(fixed), button_box, 170, 150);
  button = gtk_button_new_with_label ("Hello World");
  // Send señal (Event) clicked, execute funtion arg G_CALLBACK
  g_signal_connect (button, "clicked", G_CALLBACK (print_hello), NULL);
  // g_signal_connect_swapped (button, "clicked", G_CALLBACK (gtk_widget_destroy), window); press button = Close window
  gtk_container_add (GTK_CONTAINER (button_box), button);

  // Set properties for label
  label = gtk_label_new("soy un label");
  gtk_fixed_put(GTK_FIXED(fixed), label, 170, 20);
  gtk_container_add(GTK_CONTAINER(window), fixed);
  gtk_widget_show_all (window);
}

int main (int argc, char **argv) {
  GtkApplication *app;
  int status;

  app = gtk_application_new ("org.gtk.example", G_APPLICATION_FLAGS_NONE);
  g_signal_connect (app, "activate", G_CALLBACK (activate), NULL);
  status = g_application_run (G_APPLICATION (app), argc, argv);
  g_object_unref (app);

  return status;
}

// compiler: gcc `pkg-config --cflags gtk+-3.0` -o auto main.c `pkg-config --libs gtk+-3.0`