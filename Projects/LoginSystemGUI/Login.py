import customtkinter as ctk
from PIL import Image, ImageTk


class Login_System:
    def __init__(self, root):
        self.root = root
        self.root.title("Login System")
        self.root.geometry("300x400")
        self.root.resizable(False, False)
        title = ctk.CTkLabel(
            self.root,
            text="Programmer's Login System \n Pythonista Version",
            font=ctk.CTkFont(size=20, weight="bold"),
        )
        title.place(relx=0.5, rely=0.08, anchor=ctk.CENTER)

        # ---Images----------------------------------------------------
        self.user_image = Image.open("Login System Program/speed.png")
        self.user = ctk.CTkImage(self.user_image, size=(150, 150))
        self.user_label = ctk.CTkLabel(self.root, image=self.user)
        self.user_label.place(relx=0.5, rely=0.35, anchor=ctk.CENTER)

        # ---Input Frame----------------------------------------------------
        Input_Frame = ctk.CTkFrame(self.root)
        Input_Frame.place(relx=0.5, rely=0.7, anchor=ctk.CENTER)

        # ---Username Entry Box----------------------------------------------------
        self.username_entry = ctk.CTkEntry(Input_Frame, placeholder_text="Username")
        self.username_entry.pack(pady=10)

        # ---Password Entry Box----------------------------------------------------
        self.password_entry = ctk.CTkEntry(
            Input_Frame, placeholder_text="Password", show="*"
        )
        self.password_entry.pack(pady=10)

        # ---Submit Button----------------------------------------------------
        self.submit_button = ctk.CTkButton(
            Input_Frame, text="Submit", command=self.login
        )
        self.submit_button.pack(pady=10)

    def login(self):
        username = self.username_entry.get()
        password = self.password_entry.get()

        # TODO: Validate the username and password

        if username == "admin" and password == "password":
            # Login successful
            print("Login successful")
        else:
            # Login failed
            print("Login failed")


ctk.set_appearance_mode("dark")
root = ctk.CTk()
object = Login_System(root)

# Center the window
window_width = 300
window_height = 400
screen_width = root.winfo_screenwidth()
screen_height = root.winfo_screenheight()
x = (screen_width // 2) - (window_width // 2)
y = (screen_height // 2) - (window_height // 2)
root.geometry(f"{window_width}x{window_height}+{x}+{y}")

root.mainloop()