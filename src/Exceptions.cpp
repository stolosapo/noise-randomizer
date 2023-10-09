#include "Exceptions.h"

const DomainErrorCode GPIO0001 = DomainErrorCode("GPIO0001", "Failed to export pin '%s'");
const DomainErrorCode GPIO0002 = DomainErrorCode("GPIO0002", "Failed to unexport pin '%s'");
const DomainErrorCode GPIO0003 = DomainErrorCode("GPIO0003", "Failed to set direction for pin '%s'");
const DomainErrorCode GPIO0004 = DomainErrorCode("GPIO0004", "Failed to set value for pin '%s'");
const DomainErrorCode GPIO0005 = DomainErrorCode("GPIO0005", "Failed to get value from pin '%s'");
const DomainErrorCode GPIO0006 = DomainErrorCode("GPIO0006", "Invalid operation, oposite direction of pin '%s'");