#include <libnotify/notify.h>
#include <iostream>

class Notification
{
private:
    // Flag to control the main loop
    bool exit_program;

    // Callback function (static so it can be used as a C-style callback)
    static void action_callback(NotifyNotification *notification, char *action, gpointer user_data);

public:
    // Constructor initializes the notification library
    Notification();

    // Destructor cleans up the notification library
    ~Notification();

    // Method to send a notification with actions
    void sendNotification();
};
Notification::Notification() : exit_program(false)
{
    notify_init("Notification Class Example");
}
Notification::~Notification()
{
    notify_uninit();
}
void Notification::sendNotification()
{
    // Create the notification
    NotifyNotification *notification = notify_notification_new(
        "Action Required",         // Notification title
        "Do you agree to submit?", // Notification content
        NULL                       // Icon
    );

    // Add actions (buttons) to the notification
    notify_notification_add_action(notification,
                                   "DONE",                                  // Action ID
                                   "DONE",                                  // Button label
                                   NOTIFY_ACTION_CALLBACK(action_callback), // Callback function
                                   this,                                    // Pass this class instance as user data
                                   NULL);                                   // Free function for user data

    notify_notification_add_action(notification,
                                   "DELAYED",                               // Action ID
                                   "DELAYED",                               // Button label
                                   NOTIFY_ACTION_CALLBACK(action_callback), // Callback function
                                   this,                                    // Pass this class instance as user data
                                   NULL);

    // Show the notification with actions
    if (!notify_notification_show(notification, NULL))
    {
        std::cerr << "Failed to send notification." << std::endl;
        return;
    }

    // Main loop to handle actions (this is necessary to receive user input)
    while (!exit_program)
    {
        g_main_context_iteration(NULL, false); // Non-blocking loop iteration
    }

    // Clean up the notification object
    g_object_unref(G_OBJECT(notification));
}
void Notification::action_callback(NotifyNotification *notification, char *action, gpointer user_data)
{
    Notification *self = static_cast<Notification *>(user_data);

    if (std::string(action) == "DONE")
    {
        std::cout << "Task DONE." << std::endl;
        // Add your "agree" action code here
    }
    else if (std::string(action) == "DELAYED")
    {
        std::cout << "Task DELAYED." << std::endl;
        // Add your "disagree" action code here
    }

    // Set the flag to true to indicate the user has selected an action
    self->exit_program = true;
}
int main()
{
    // Create an instance of the Notification class
    Notification notification;

    // Send the notification with actions
    notification.sendNotification();

    return 0;
}
