
class Lung
{

Public:
	Lung();
	

Private:
	const int Compliance_ = 10;
	const int Resistance_ = 20;
	float AirwaysPressure(float incoming_volume);

} // End of Class definition