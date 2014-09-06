(function ($) {
  Drupal.admin.behaviors.theArkAdminFormDateEvents = function () {
    var eventForm = $('#event-node-form');
    if (eventForm.length === 0) return;

    var dateDoorsField = $('.form-item-field-date-doors-und-0-value-date .form-text')
      , dateShowField = $('.form-item-field-date-und-0-value-date .form-text');

    if (dateDoorsField.length === 0 || dateShowField.length === 0) return;

    var dateShowFieldValue = dateShowField.val(); // store value for comparative purposes

    dateShowField.change(function () {
      // only change doors date if it was previously the same as the show date
      if (dateDoorsField.val() === dateShowFieldValue) dateDoorsField.val(dateShowField.val());
      dateShowFieldValue = dateShowField.val();
    });

  };
})(jQuery);
