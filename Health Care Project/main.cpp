#include <iostream>
#include<vector>
#include <memory>
#include<string>
#include<limits>

using namespace::std;

//Abstracting Base Class representing a general Health Module
class HealthModule {
	public:
		virtual ~HealthModule() = default;
		virtual string getTitle() const = 0;
		virtual void execute() =0;
};

//Class handling body weight evaluation
class WeightModule : public HealthModule {
	private:
		int age;
		double weight;
		
		//Encapsulated evaluation logic
		bool isWeightAppropriate() const {
		if(age >= 18) {
		return (weight >= 50.0 && weight<= 80.0);
		}
		return (weight >= 15.0 && weight < 50.0);
	}
	
	public:
		string getTitle() const override {
		return "Body weight for age";
		}
		
		void execute() override {
		cout<< "\n--- Body Weight Evaluation ---" << endl;
		cout<< "Enter age: ";
		cin >> age;
		cout << "Enter weight (kg): ";
		cin >> weight;
		
		if(isWeightAppropriate()){
			cout<< "\nStatus: RIGHT??" << endl;
			cout<< "Your weight is appropriate for your age." << endl;
		} else {
		    cout << "\nStatus: WRONG??" << endl;
			cout << "Your weight is outside the recommended range." << endl;
			cout << "1. Consult a certified nutritionist." << endl;
			cout << "2. Maintaine a balanced daily calorie intake." << endl;
			cout << "3. Engage in regular physical activity." << endl;
		}
		}
};


//Class handling Blood Pressure information
class BloodPressureModule : public HealthModule {
	public:
		string getTitle() const override {		
		    return "Blood pressure problem causes & precautions";
		}
		
		void execute() override {
			cout << "\n--- Blood Pressure Information ---" << endl;
			cout << "\nCauses:" << endl;
			cout << "- High sodium consumption" << endl;
			cout << "- Stress and smoking" << endl;
			
			cout << "\nPrecautions: " << endl;
			cout << "-Reduce daily salt intake." << endl;
			cout << "-Exercise for 30 minutes daily." << endl;
			cout << "-Perform routine BP monitoring." << endl;
		}
};


//Class handling Sugar (Diabetes) information
class SugarModule : public HealthModule {
	public:
		string getTitle() const override {
			return "Sugar symptoms & causes";
		}
		
		void execute() override {
			cout << "\n--- Sugar (Diabetes) Information ---" << endl;
			cout << "\nCauses:" << endl;
			cout << "-Ecessive consumption of refined sugars" << endl;
			cout << "-Sedentary lifestyle and genetic fector" << endl;
			
			cout << "\nSymptoms:" << endl;
			cout << "-Frequent urination and excessive thirst" << endl;
			cout << "-Blurry vision and unexplained fatigue" << endl;
			
			cout << "\nPrecautions:" << endl;
			cout << "\n- Limit intake of sugary foods and drinks." << endl;
			cout << "\n- Maintain regular blood glucose checks." << endl;
			cout << "\n- Consume fiber-rich meals." << endl;
		}
};

//Class handling Heart Attack Information
class HeartAttackModule : public HealthModule {
	public:
		string getTitle() const override {
			return "Heart attack symptoms & causes";
		}
		
		void execute() override {
			cout << "\n--- Heart Attack Information ---" << endl;
			cout << "\nCauses:" << endl;
			cout << "- Heigh cholestrol and high blood pressure" << endl;
			cout << "- Smoking and physical inactivity" << endl;
			
			cout << "\nSymptoms:" << endl;
			cout << "- Severe chest pain or tightness" << endl;
			cout << "- Shortness of breath and cold sweats" << endl;
			
			cout << "\nPrecautions:" << endl;
			cout << "- Eat a heart-healthy diet low in saturated fats." << endl;
			cout << "- Avoid tobacco and manage daily stress levels." << endl;
			cout << "- Schedule routine cardiovascular health check-ups." << endl;
		}
};


//Controller class managing application flow and menu options
class HealthCareConsole {
	private:
		vector<unique_ptr<HealthModule>> modules;
		
		void displayMenu() const {
			cout << "\n=========================================" << endl;
			cout << "       HEALTH CARE CONSOLE APPLICATION     " << endl;
			cout << "\n=========================================" << endl;
			
			for(size_t i = 0; i < modules.size(); ++i) {
				cout << (i+1) << ". " << modules[i]->getTitle() << endl;
			}
			
			cout << (modules.size() + 1) << ". Exit" << endl;
			cout << "Select an option: ";
			
		}
		
	public:
		HealthCareConsole(){
			modules.push_back(make_unique<WeightModule>());
			modules.push_back(make_unique<BloodPressureModule>());
			modules.push_back(make_unique<SugarModule>());
			modules.push_back(make_unique<HeartAttackModule>());
			
		}
		
		void start() {
			int choice = 0;
			const int exitOption = static_cast<int>(modules.size()) + 1;
			
			do {
				displayMenu();
				if(!(cin >> choice)) {
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "\nInvalid input. Please enter a valid number!" << endl;
					continue;
				}
				
				if(choice >= 1 && choice <= static_cast<int>(modules.size())) {
					modules[choice - 1]->execute();
				} else if(choice == exitOption) {
					cout << "\nPress any key to exit!" << endl;
				} else {
					cout << "\nInvalid input. Please enter a valid number!" << endl;
				}
			} while (choice != exitOption);		
		}
};


int main(int argc, char** argv) {
	HealthCareConsole app;
	app.start();
	
	return 0;
}
