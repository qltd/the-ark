(function ($) {
  Drupal.admin.behaviors.theArkAdminFormDateSoundTech = function () {
    var soundTechForm = $('#sound-tech-node-form');
    if (soundTechForm.length === 0) return;

    var dateField = $('.form-item-field-date-und-0-value-date .form-text')
      , timeField = $('.form-item-field-date-und-0-value-time .form-text')
      , eventDateRaw = $.getQueryParameters().field_date;

    if (dateField.length === 0 || !eventDateRaw || dateField.val()) return;

    var eventDate = new Date(new Date(parseInt(eventDateRaw) * 1000).toDateString() + ' UTC')
      , eventDateFormatted = (eventDate.getMonth() + 1) + '/' + eventDate.getDate() + '/' + eventDate.getFullYear();

    timeField.val('05:00pm');
    dateField.val(eventDateFormatted);
  };
})(jQuery);
